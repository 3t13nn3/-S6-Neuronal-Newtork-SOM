#include "init_network.h"

void init_empty_neuron(Neuron* n, uint size){
	n->data_ = malloc((size_t) size * sizeof(double));
	n->size_ = size;
}

void init_neuron_from_element(Neuron* n, Element e){
	n->data_ = malloc((size_t) e.size_ * sizeof(double));
	n->size_ = e.size_;
	n->data_ = e.data_;
	n->name_ = e.name_;
}

void init_neuron_network(Neuron_network * network, Element * all_element, Configuration c){
	uint i;
	uint j;
	double variation_value;
	double* average = malloc((size_t) c.data_size_ * sizeof(double));
	//summing all data value into our average vec
	for(i=0; i<c.global_size_; ++i){
		for(j=0; j<c.data_size_; ++j){
			average[j]+=all_element[i].data_[j];
		}
	}
	//deviding our average vec by the number of components
	for(j=0; j<c.data_size_; ++j){
		average[j]/=c.global_size_;
	}
	//assigment for each neurons with a little variation
	for(i=0 ; i< network->size_; ++i){
		for(j=0; j< c.data_size_; ++j){
			variation_value = ((double)rand()*(MAX - MIN))/(double)RAND_MAX + MIN;
			network->all_the_neurons_[i].data_[j] = average[j] + variation_value;
		}
	}
}


//Seems to be ok, MUST VERIFY
void learning(Neuron_network * network, Element * learning_data, Configuration c){
	uint         i;
	uint         current_neuron;
	uint         current_data;
	double       dist;
	Neuron_list* winners;

	/*INDEX INIT*/
	uint* indexs = malloc((size_t) c.global_size_ * sizeof(uint));
	for(i=0; i<c.global_size_; ++i){
		indexs[i] = i;
	}

	/*searching for the best one */
	for(current_neuron=0; current_neuron<network->size_; current_neuron++){
		winners = init_neuron_list(c.data_size_);
		for(current_data=0; current_data<c.global_size_; current_data++){
			dist = Euclidian_dist(network->all_the_neurons_[current_neuron].data_,learning_data[current_data].data_,c.data_size_);
			switch(compare_neuron_to_list(winners, dist)){
				case LOWER:
					//on supprime la list et on ajoute notre nouveau neurone
					delete_all_neurons_list(winners);
					push_neuron_list(winners, learning_data[current_data], dist);
					break;
				case EQUAL:
					//on ajoute seuelemtn
					push_neuron_list(winners, learning_data[current_data], dist);
					break;
				case GREATER:
					//on fait rien
					break;
				case ERROR:
					printf("ERROR DURING NEURON %d LEARNING\n",current_neuron);
					break;
				default: break;
			}
		}
		printf("\n\n%d\n", current_neuron);
		neuron_list_printer(winners,c.data_size_);
		delete_all_neurons_list(winners);
	}

}