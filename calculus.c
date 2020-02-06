#include "calculus.h"

void normalize(Iris * current_iris, uint size){
	uint i;
	double result = 0;
	for(i=0 ; i<size ; ++i){
		result+= current_iris->data[i]*current_iris->data[i];
	}
	current_iris->norm = sqrt(result);

	for(i=0 ; i<size ; ++i){
		current_iris->data[i]/=current_iris->norm;
	}
}

double Euclidian_dist(double * a, double * b, uint size){
	double result = 0;
	uint i;
	for(i=0; i<size; ++i){
		result+= (a[i] - b[i]) * (a[i] - b[i]);
	}
	return sqrt(result);
}