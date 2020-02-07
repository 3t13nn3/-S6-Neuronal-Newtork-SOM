#include "init_network.h"

void init_neuron(Neuron* n, uint size){
	n->data_ = malloc((size_t) size * sizeof(double));
	n->size_ = size;
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

void learning(Neuron_network * network, Element * learning_data, Configuration c){
	uint         i;
	uint         current_neuron;
	uint         current_data;
	Neuron_list* winners = init_neuron_list(c.data_size_);

	/*INDEX INIT*/
	uint* indexs = malloc((size_t) c.global_size_ * sizeof(uint));
	for(i=0; i<c.global_size_; ++i){
		indexs[i] = i;
	}

	for(current_neuron=0; current_neuron<network->size_; current_neuron++){
		for(current_data=0; current_data<c.global_size_; current_data++){

		}
	}

}