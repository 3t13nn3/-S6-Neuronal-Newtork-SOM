#ifndef NEURON_LIST_DEF_ONCE
#define NEURON_LIST_DEF_ONCE

#include <stdlib.h>
#include <stdio.h>

#include "struct.h"
#include "init_network.h"

#define INF     999999
#define ERROR   -1
#define EQUAL   0
#define GREATER 1
#define LOWER   2

Neuron_list* init_neuron_list(uint data_size);
void push_neuron_list(Neuron_list* list, Neuron n, double dist);
void pop_neuron_list(Neuron_list* list);
void delete_all_neurons_list(Neuron_list* list);
int  compare_neuron_to_list(Neuron_list* list, double dist);

#endif