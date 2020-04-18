#include "neuron_list.h"

Neuron_list* init_neuron_list(){
	Neuron_list* list = malloc(sizeof(Neuron_list));
	Neuron_node* node = malloc(sizeof(Neuron_node));

	if(node != NULL && list != NULL){

		node->index_ = 0;
	    node->next_ = NULL;
	    node->dist_ = INF;
	    list->first_ = node;
	    return list;

	} else {
		printf("ERROR ON LIST INIT\n");
		exit(0);
	}
	return list;
}

void push_neuron_list(Neuron_list* list, int index, double dist){
	Neuron_node* new = malloc(sizeof(Neuron_node));

	if(new != NULL && list != NULL){
		new->index_ = index;
		new->next_ = list->first_;
		new->dist_ = dist;
		list->first_ = new;

	} else {

		printf("ERROR ON LIST PUSH\n");
		exit(0);
	}
}

void pop_neuron_list(Neuron_list* list){

    if (list->first_ != NULL){

        Neuron_node* to_delete = list->first_;
        list->first_ = list->first_->next_;
        free(to_delete);

    } else {

		printf("ERROR ON LIST POP\n");
		exit(0);
	}
}

void delete_all_neurons_list(Neuron_list* list){

    Neuron_node* current = list->first_;

    while (current != NULL){

    	pop_neuron_list(list);
        current = current->next_;
    }
}

int compare_neuron_to_list(Neuron_list* list, double dist){
	if(list != NULL){
		if(list->first_->dist_ > dist){
			return LOWER;
		} else if(list->first_->dist_ == dist){
			return EQUAL;
		} else {
			return GREATER;
		}
	} else {
		printf("COMPARE FAIL: EMPTY LIST\n");
		return ERROR;
	}
}

int get_neuron_index_from_index(Neuron_list* list, int index){

	int cpt = 1;
	Neuron_node* current = list->first_;

	while (cpt < index){
		current = current->next_;
	}

	return current->index_;
}
