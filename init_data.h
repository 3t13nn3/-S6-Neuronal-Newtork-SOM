#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "struct.h"
#include "calculus.h"

uint count_datas(char* filename);
Iris recovery_data(char* current_iris, uint size);
void filling_data_from_file(char* filename, Iris **all_iris, Configuration c);