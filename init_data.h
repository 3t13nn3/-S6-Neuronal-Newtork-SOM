#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "struct.h"
#include "calculus.h"

uint count_datas(char* filename);
Element recovery_data(char* current_element, uint size);
void filling_data_from_file(char* filename, Element **all_element, Configuration c);