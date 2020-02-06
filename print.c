#include "print.h"

void display_datas(Element ** all_element, Configuration c){
	uint i;
	uint j;
	for(i=0; i < c.global_size; i++){
		printf("Element %d:\n\t|", i);
		for(j=0; j < c.data_size; j++){
			printf("%f|",(*all_element)[i].data[j]);
		}
	printf("\n\t%s\n",(*all_element)[i].name);
	printf("\tnorm: %.3e\n",(*all_element)[i].norm);
	}
}