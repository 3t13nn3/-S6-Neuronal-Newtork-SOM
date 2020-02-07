#include "head.h"

#define DEBUG

int main(int argc, char ** argv){

	srand(time(NULL));
	uint i;
	/*INIT ARG*/
	if(argc > 2){
		printf("Usage: ./nn.out (file.data)\n");
		return -1;
	}
	char* file_name = (argc == 1) ? "Data/iris.data" : argv[1];

	/*INIT DATA*/
	Configuration c;
	c.global_size_ = count_datas(file_name);
	c.data_size_   = 4;

    Element* global_data = malloc((size_t) c.global_size_ * sizeof(Element));
	for(i=0; i< c.global_size_; ++i){
		global_data->data_ = malloc((size_t) c.data_size_ * sizeof(double));
		global_data->size_ = c.data_size_;
	}


    filling_data_from_file(file_name, &global_data, c);

#ifdef DEBUG
    display_datas(global_data, c);
#endif

	/*INIT NETWORK*/
	Neuron_network network;

	network.size_ = NEURON_SIZE(c.global_size_);
	network.all_the_neurons_ = malloc((size_t) network.size_ * sizeof(Neuron));

	for(i=0; i< c.global_size_; ++i){
		init_neuron(&network.all_the_neurons_[i], c.data_size_);
	}
	
	init_neuron_network(&network,global_data,c);
	learning(&network, global_data, c);
	return 0;
}