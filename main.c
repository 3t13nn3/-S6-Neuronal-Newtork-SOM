#include "head.h"

#define DEBUG

int main(){
	/*INIT*/
	Configuration c;
	c.global_size = count_datas("iris.data");
	c.data_size   = 4;
    Iris* global_data = malloc((size_t) c.global_size * sizeof(Iris));
	for(uint i=0; i< c.global_size; ++i){
		global_data->data = malloc((size_t) c.data_size * sizeof(double));
	}


    filling_data_from_file("iris.data", &global_data, c);

#ifdef DEBUG
    display_datas(&global_data, c);
#endif

	//define the all neurons sizes
	Neuron_network network;
	network.size = NEURON_SIZE(c.global_size);
	network.all_the_neurons = malloc((size_t) network.size * sizeof(Neuron));
	for(uint i=0; i< c.global_size; ++i){
		network.all_the_neurons[i].data = malloc((size_t) c.data_size * sizeof(double));
	}
	init_neurons(&network,global_data,c);
	return 0;
}