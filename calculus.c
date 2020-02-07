#include "calculus.h"

void normalize(Element * current_element, uint size){
	uint i;
	double result = 0;
	for(i=0 ; i<size ; ++i){
		result+= current_element->data_[i]*current_element->data_[i];
	}
	current_element->norm_ = sqrt(result);

	for(i=0 ; i<size ; ++i){
		current_element->data_[i]/=current_element->norm_;
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