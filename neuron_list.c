#include "neuron_list.h"

Neuron_list* init_neuron_list(uint data_size){
	Neuron_list* list = malloc(sizeof(Neuron_list));
	Neuron_node* node = malloc(sizeof(Neuron_node));

	if(node != NULL && list != NULL){
		Neuron n;
		init_neuron(&n, data_size);
		node->neur_ = n;
	    node->next_ = NULL;
	    list->first_ = node;
	    return list;
	} else {
		printf("ERROR ON LIST INIT");
	}
	return list;
}

void push_neuron_list(Neuron_list* list, Neuron n){
	Neuron_node* new = malloc(sizeof(Neuron_node));

	if(new != NULL && list != NULL){
		new->neur_ = n;
		new->next_ = list->first_;
		list->first_ = new;
	} else {
		printf("ERROR ON LIST PUSH");
	}
}

void pop_neuron_list(Neuron_list* list){
    if (list->first_ != NULL){
        Neuron_node* to_delete = list->first_;
        list->first_ = list->first_->next_;
        free(to_delete);
    } else {
		printf("ERROR ON LIST POP");
	}
}