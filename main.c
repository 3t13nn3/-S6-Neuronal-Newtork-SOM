#include "head.h"

#define DEBUG

int main(int argc, char ** argv){

	srand(time(NULL));

	/*INIT ARG*/
	if(argc > 2){
		printf("Usage: ./nn.out (file)\n");
		return -1;
	}
	char* file_name = (argc == 1) ? "Data/iris.data" : argv[1];

	/*INIT DATA*/
	Configuration c;
	c.global_size = count_datas(file_name);
	c.data_size   = 4;

    Element* global_data = malloc((size_t) c.global_size * sizeof(Element));
	for(uint i=0; i< c.global_size; ++i){
		global_data->data = malloc((size_t) c.data_size * sizeof(double));
	}

    filling_data_from_file(file_name, &global_data, c);

#ifdef DEBUG
    display_datas(&global_data, c);
#endif

	/*INIT NETWORK*/
	Neuron_network network;
	network.size = NEURON_SIZE(c.global_size);
	network.all_the_neurons = malloc((size_t) network.size * sizeof(Neuron));
	for(uint i=0; i< c.global_size; ++i){
		network.all_the_neurons[i].data = malloc((size_t) c.data_size * sizeof(double));
	}
	init_neurons(&network,global_data,c);

	return 0;
}