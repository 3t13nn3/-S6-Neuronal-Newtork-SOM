#include <math.h>

#include "struct.h"

#define NEURON_SIZE(N) 5*sqrt(N)

void   normalize(Element * current_element, uint size);
double Euclidian_dist(double * a, double * b, uint size);