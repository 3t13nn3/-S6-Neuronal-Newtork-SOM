/*DATA STRUCT*/
//#pragma once
#ifndef STRUCT_DEF_ONCE
#define STRUCT_DEF_ONCE
 

typedef unsigned int uint;

struct configuration{
	uint global_size;
	uint data_size;
};
typedef struct configuration Configuration;

struct element {
	double* data; /*sepal_lenght;
					sepal_width;
					petal_length;
					petal_width;*/
    char*   name;
	double  norm;
};
typedef struct element Element;

struct neuron{
	double* data;
};
typedef struct neuron Neuron;

struct neuron_network{
	Neuron * all_the_neurons;
	uint size;
};
typedef struct neuron_network Neuron_network;

#endif