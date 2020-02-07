/*DATA STRUCT*/
//#pragma once
#ifndef STRUCT_DEF_ONCE
#define STRUCT_DEF_ONCE
 

typedef unsigned int uint;

struct configuration{
	uint global_size_;
	uint data_size_;
};
typedef struct configuration Configuration;

struct element{
	double* data_;
	uint    size_;
    char*   name_;
	double  norm_;
};
typedef struct element Element;

struct neuron{
	double* data_;
	uint    size_;
		char*   name_; ////debug
};
typedef struct neuron Neuron;

struct neuron_network{
	Neuron* all_the_neurons_;
	uint  	size_;
	uint    width_;
};
typedef struct neuron_network Neuron_network;


//neuronal list

typedef struct neuron_node Neuron_node;
struct neuron_node{
	Neuron       neur_;
	double       dist_;
	Neuron_node* next_;
};

struct neuron_list {
	Neuron_node* first_;
};
typedef struct neuron_list Neuron_list;


#endif