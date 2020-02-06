#include "print.h"

void display_datas(Iris ** all_iris, Configuration c){
	uint i;
	uint j;
	for(i=0; i < c.global_size; i++){
		printf("Element %d:\n\t|", i);
		for(j=0; j < c.data_size; j++){
			printf("%f|",(*all_iris)[i].data[j]);
		}
	printf("\n\t%s\n",(*all_iris)[i].name);
	printf("\tnorm: %.3e\n",(*all_iris)[i].norm);
	}
}