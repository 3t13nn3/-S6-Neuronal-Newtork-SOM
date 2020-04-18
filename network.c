#include "network.h"

void init_empty_neuron(Neuron* n, uint size) {
    n->data_ = malloc((size_t)size * sizeof(double));
    n->size_ = size;
    n->ID_ = 0;
}

void init_neuron_network(Neuron_network* network, Element* all_element, Configuration c) {
    uint i;
    uint j;
    double variation_value;
    double* average = malloc((size_t)c.data_size_ * sizeof(double));

    //summing all data value into our average vec
    for (i = 0; i < c.global_size_; ++i) {
        for (j = 0; j < c.data_size_; ++j) {
            average[j] += all_element[i].data_[j];
        }
    }
    //deviding our average vec by the number of components
    for (j = 0; j < c.data_size_; ++j) {
        average[j] /= c.global_size_;
    }
    //assigment for each neurons with a little variation
    for (i = 0; i < network->size_; ++i) {
        for (j = 0; j < c.data_size_; ++j) {
            variation_value = ((double)rand() * (MAX - MIN)) / (double)RAND_MAX + MIN;
            network->all_the_neurons_[i].data_[j] = average[j] + variation_value;
        }
    }
}

void learning(Neuron_network* network, Element* learning_data, Configuration c, double alpha, int number_of_layers) {
    uint i;
    uint current_neuron;
    uint current_data;
    double dist;
    Neuron_list* winners;
    int list_size = 0;
    uint winner;

    /*INDEX INIT*/
    uint* indexs = malloc((size_t)c.global_size_ * sizeof(uint));
    for (i = 0; i < c.global_size_; ++i) {
        indexs[i] = i;
    }
    /*INDEX SHUFFLE*/
    for (i = 0; i < c.global_size_; ++i) {
        uint rand_index = rand() % c.global_size_;
        uint tmp = indexs[i];
        indexs[i] = indexs[rand_index];
        indexs[rand_index] = tmp;
    }

    /*searching for the neuron for each data*/
    for (current_data = 0; current_data < c.global_size_; current_data++) {
        winners = init_neuron_list();
        for (current_neuron = 0; current_neuron < network->size_; current_neuron++) {
            dist = Euclidian_dist(network->all_the_neurons_[current_neuron].data_, learning_data[indexs[current_data]].data_, 4);
            //printf("dist %d: %f\n", current_neuron, dist);

            switch (compare_neuron_to_list(winners, dist)) {
                case LOWER:
                    //on supprime la list et on ajoute notre nouveau neurone
                    list_size = 1;
                    winner = current_neuron;
                    delete_all_neurons_list(winners);
                    push_neuron_list(winners, current_neuron, dist);
                    break;
                case EQUAL:
                    //on ajoute seuelemtn
                    list_size++;
                    push_neuron_list(winners, current_neuron, dist);
                    break;
                case GREATER:
                    //on fait rien
                    break;
                case ERROR:
                    printf("ERROR DURING NEURON %d LEARNING\n", current_neuron);
                    break;
                default:
                    break;
            }
        }

#ifdef DEBUG_LIST_DISPLAY
		printf("\n\n%d\n", indexs[current_data]);
		neuron_list_printer(winners,c.data_size_);
#endif

        diffuse(alpha, winner, network, number_of_layers, learning_data[indexs[current_data]].data_);
        delete_all_neurons_list(winners);
    }
}

void adapt(Neuron_network* network, Element* learning_data, Configuration c) {
    int i;
    int number_of_layers;
    int number_of_neurons;

    double alpha;

    number_of_layers = 0;
    number_of_neurons = 1;
    //layer may take more than 50% of neurons in the first phase
    for (i = 1; number_of_neurons <= (int)(network->size_ / 2); ++i) {
        number_of_neurons += (i * 2) * 4;
        number_of_layers++;
    }

    for (i = 0; i < NB_PASS / 4; ++i) {
	    alpha = 0.7 * (1.0 - ((double)i / (double)(NB_PASS / 4)));
        learning(network, learning_data, c, alpha, number_of_layers);
    }

    number_of_layers = 1;
    for (i = 0; i < NB_PASS - (NB_PASS / 4); ++i) {
        alpha = 0.07 * (1.0 - ((double)i / (double)(NB_PASS - (NB_PASS / 4))));
        learning(network, learning_data, c, alpha, number_of_layers);
    }
}

void diffuse(double alpha, int neuron_index, Neuron_network* network, int number_of_layers, double* data) {
    int i, j, k;
    int current_index;
    int x, y;

    x = (neuron_index % network->width_) - number_of_layers;
    y = (neuron_index / network->width_) - number_of_layers;

    for (i = x; i <= x + (2 * number_of_layers); ++i) {

        for (j = y; j <= y + (2 * number_of_layers); ++j) {

            current_index = i + (j * network->width_);

            if (current_index >= 0 && current_index < network->size_) {

                for (k = 0; k < 4; ++k) {
                    //Wi(t+1) = Wij(t)   + alpha(t) * (x(i) - Wij(t))
                    network->all_the_neurons_[current_index].data_[k] += alpha * (data[k] - network->all_the_neurons_[current_index].data_[k]);
                }

            }

        }

    }

}

void labeling(Neuron_network* network, Element* learning_data, Configuration c) {
    uint current_neuron;
    uint current_data;
    double best_dist, dist;
    Element nearest_data;
    int to_keep;
    int list_size = 1;
    Neuron_list* winners;

    winners = init_neuron_list();

    for (current_data = 0; current_data < c.global_size_; current_data++) {
        winners = init_neuron_list();
        best_dist = INF;
        for (current_neuron = 0; current_neuron < network->size_; current_neuron++) {
            dist = Euclidian_dist(network->all_the_neurons_[current_neuron].data_, learning_data[current_data].data_, 4);
            //printf("dist %d: %f\n", current_neuron, dist);

            switch (compare_neuron_to_list(winners, dist)) {
                case LOWER:
                    //on supprime la list et on ajoute notre nouveau neurone
                    list_size = 1;
                    delete_all_neurons_list(winners);
                    push_neuron_list(winners, current_neuron, dist);
                    break;
                case EQUAL:
                    //on ajoute seuelemtn
                    list_size++;
                    push_neuron_list(winners, current_neuron, dist);
                    break;
                case GREATER:
                    //on fait rien
                    break;
                case ERROR:
                    printf("ERROR DURING NEURON %d LEARNING\n", current_neuron);
                    break;
                default:
                    break;
            }
        }

        for (int i = 0; i < list_size; ++i) {
            int index = get_neuron_index_from_index(winners, i);
            //set label
            if (strcmp(learning_data[current_data].name_, "Iris-setosa") == 0) {
                //printf("1");
                network->all_the_neurons_[index].ID_ = 1;
            } else if (strcmp(learning_data[current_data].name_, "Iris-versicolor") == 0) {
                //printf("2");
                network->all_the_neurons_[index].ID_ = 2;
            } else if (strcmp(learning_data[current_data].name_, "Iris-virginica") == 0) {
                //printf("3");
                network->all_the_neurons_[index].ID_ = 3;
            }
        }
    }
}

void print_network(Neuron_network* network) {

    int current_neuron;

	printf("\n\x1B[30m\x1B[44mNon assigned neuron: 0\x1B[49m\n");
	printf("\x1B[30m\x1B[43mIris-setosa: 1\x1B[49m\n");
	printf("\x1B[30m\x1B[45mIris-versicolor: 2\x1B[49m\n");
	printf("\x1B[30m\x1B[42mIris-virginica: 3\x1B[49m\x1B[39m\n");
	printf("-------------------------\n");

    for (current_neuron = 0; current_neuron < network->size_; current_neuron++) {

		switch(network->all_the_neurons_[current_neuron].ID_){

			case 0:
				printf("\x1B[30m\x1B[44m %d \x1B[49m",network->all_the_neurons_[current_neuron].ID_);
				break;

			case 1:
				printf("\x1B[30m\x1B[43m %d \x1B[49m",network->all_the_neurons_[current_neuron].ID_);
				break;

			case 2:
				printf("\x1B[30m\x1B[45m %d \x1B[49m",network->all_the_neurons_[current_neuron].ID_);
				break;

			case 3:
				printf("\x1B[30m\x1B[42m %d \x1B[49m",network->all_the_neurons_[current_neuron].ID_);
				break;

			default:
				break;
		}

        if ((current_neuron+1)% network->width_ == 0) {
            printf("\n");
        }
    }
    printf("\n");
}
