#include <math.h>

#include "struct.h"

#define NEURON_SIZE(N) 5*sqrt(N)

void   normalize(Iris * current_iris, uint size);
double Euclidian_dist(double * a, double * b, uint size);