#include "print.h"

void display_datas(Element * all_element, Configuration c){
	uint i;
	uint j;
	for(i=0; i < c.global_size_; i++){
		printf("Element %d:\n\t|", i);
		for(j=0; j < c.data_size_; j++){
			printf("%f|",all_element[i].data_[j]);
		}
	printf("\n\t%s\n",all_element[i].name_);
	printf("\tnorm: %.3e\n",all_element[i].norm_);
	}
}

void neuron_list_printer(Neuron_list* list, uint data_size){
	uint i;
    if (list == NULL){
        printf("ERROR ON LIST PRINT");
    }
    else{
	    Neuron_node* current = list->first_;
	    while (current != NULL){
	    	printf("|");
	    	for(i=0; i < data_size; i++){
				printf("%f|",current->neur_.data_[i]);
			}
	        printf("\n-> ");
	        current = current->next_;
	    }
	    printf("TOP OF LIST\n");
	}
}