#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <stdlib.h>

int main() {
	int a = INT_MAX;
	float b = FLT_MAX;
	double c = DBL_MAX;

	printf("int: max_value - %d, size - %lu", a, sizeof(int));
	printf("float: max_value - %g, size - %lu", b, sizeof(float));
	printf("double: max_value - %g, size - %lu", c, sizeof(double));

	return 0;
} 
