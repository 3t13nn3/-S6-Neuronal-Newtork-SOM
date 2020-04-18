#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "struct.h"
#include "neuron_list.h"
#include "calculus.h"
#include "print.h"

#define MIN -0.05
#define MAX 0.025

#define NB_PASS 2000

//#define DEBUG_LIST_DISPLAY

void init_empty_neuron(Neuron* n, uint size);
void init_neuron_network(Neuron_network * network, Element * all_element, Configuration c);
void learning(Neuron_network * network, Element * learning_data, Configuration c, double alpha, int number_of_layers);
void adapt(Neuron_network * network, Element * learning_data, Configuration c);
void diffuse(double alpha, int neuron_index, Neuron_network * network, int number_of_layers, double * data);
void labeling(Neuron_network * network, Element * learning_data, Configuration c);
void print_network(Neuron_network * network);
