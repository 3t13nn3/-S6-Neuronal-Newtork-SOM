#include "init_data.h"

/*Counting the numbers of datas*/
uint count_datas(char* filename){
	/*counting number of datas*/
	int size = -1;
	char c;

	FILE* file = NULL;
    file = fopen(filename, "r");

    if(file != NULL){
    	while((c = fgetc(file)) != EOF){
    		if(c == '\n')
    			size++;
    	}
    }
    fclose(file);

    return size;
}


/*Recovering an element data into an element struct*/
Element recovery_data(char* current_element, uint size){
	const char s[3] = ",\n";
	char       element_string[256];
	int        cpt = 0;
	char*      token;
   	Element    to_return;

    to_return.data = malloc((size_t) size * sizeof(double));

   	
	strcpy(element_string, current_element);
	
	/* get the first token */
	token = strtok(element_string, s);

	while(token != NULL){
		switch(cpt){
			case 0:
				to_return.data[0] = strtod(token,NULL);
				break;
			case 1:
				to_return.data[1] = strtod(token,NULL);
				break;
			case 2:
				to_return.data[2] = strtod(token,NULL);
				break;
			case 3:
				to_return.data[3] = strtod(token,NULL);
				break;
			default:
				to_return.name = malloc((size_t) strlen(token) * sizeof(char));
				to_return.name = token;
				break;
		}

    	token = strtok(NULL, s);
    	cpt++;
	}
	normalize(&to_return, size);
	return to_return;
}


void filling_data_from_file(char* filename, Element **all_element, Configuration c){
	uint cpt = 0;
			
	FILE* file = NULL;
	file = fopen(filename, "r");

    if(file != NULL){
    	char line [128];
	    while(cpt < c.global_size){
	    	fgets(line, sizeof line, file);
	    	(*all_element)[cpt] = recovery_data(line,c.data_size);
	    	cpt++;
	    }
    }
    fclose(file);
}