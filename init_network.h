#include <stdlib.h>
#include <time.h>

#include "struct.h"
#include "neuron_list.h"
#include "calculus.h"
#include "print.h"

#define MIN -0.05
#define MAX 0.025

void init_empty_neuron(Neuron* n, uint size);
void init_neuron_from_element(Neuron* n, Element e);
void init_neuron_network(Neuron_network * network, Element * all_element, Configuration c);
void learning(Neuron_network * network, Element * learning_data, Configuration c);