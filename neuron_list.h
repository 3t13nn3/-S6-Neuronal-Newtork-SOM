#ifndef NEURON_LIST_DEF_ONCE
#define NEURON_LIST_DEF_ONCE

#include <stdlib.h>
#include <stdio.h>

#include "struct.h"
#include "network.h"

#define INF     999999
#define ERROR   -1
#define EQUAL   0
#define GREATER 1
#define LOWER   2

Neuron_list* init_neuron_list();

void push_neuron_list(Neuron_list* list, int index, double dist);

void pop_neuron_list(Neuron_list* list);

void delete_all_neurons_list(Neuron_list* list);

int compare_neuron_to_list(Neuron_list* list, double dist);

int get_neuron_index_from_index(Neuron_list* list, int index);

#endif