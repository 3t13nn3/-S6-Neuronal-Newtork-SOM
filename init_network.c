#include "init_network.h"

void init_neurons(Neuron_network * network, Iris * all_iris, Configuration c){
	uint i;
	uint j;
	double* average = malloc((size_t) c.data_size * sizeof(double));
	//summing all data value into our average vec
	for(i=0; i<c.global_size; ++i){
		for(j=0; j<c.data_size; ++j){
			average[j]+=all_iris[i].data[j];
		}
	}
	//deviding our average vec by the number of components
	for(j=0; j<c.data_size; ++j){
		average[j]/=c.global_size;
	}
	//assigment for each neurons
	for(i=0 ; i< network->size; ++i){
		for(j=0; j< c.data_size; ++j){
			network->all_the_neurons[i].data[j] = average[j];
		}
	}
}