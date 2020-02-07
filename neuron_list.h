#ifndef NEURON_LIST_DEF_ONCE
#define NEURON_LIST_DEF_ONCE

#include <stdlib.h>
#include <stdio.h>

#include "struct.h"
#include "init_network.h"

Neuron_list* init_neuron_list(uint data_size);
void push_neuron_list(Neuron_list* list, Neuron n);
void pop_neuron_list(Neuron_list* list);

#endif