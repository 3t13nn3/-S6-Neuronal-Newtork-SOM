#include "init_network.h"

void init_neurons(Neuron_network * network, Element * all_element, Configuration c){
	uint i;
	uint j;
	double variation_value;
	double* average = malloc((size_t) c.data_size * sizeof(double));
	//summing all data value into our average vec
	for(i=0; i<c.global_size; ++i){
		for(j=0; j<c.data_size; ++j){
			average[j]+=all_element[i].data[j];
		}
	}
	//deviding our average vec by the number of components
	for(j=0; j<c.data_size; ++j){
		average[j]/=c.global_size;
	}
	//assigment for each neurons with a little variation
	for(i=0 ; i< network->size; ++i){
		for(j=0; j< c.data_size; ++j){
			variation_value = ((double)rand()*(MAX - MIN))/(double)RAND_MAX + MIN;
			network->all_the_neurons[i].data[j] = average[j] + variation_value;
		}
	}
}