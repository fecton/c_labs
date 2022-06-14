#include <stdio.h>
#include <math.h>

const double
	n = 140.0,
	a = 0.2,
	b = 0.8;

int factorial(int x) {
	if (x <= 0) {
		return 0;
	}

	int fact = 1;
	for (int i = 2; i <= x; i++) {
		fact *= i;
	}
	return fact;
}

double S(double x) {
	double res = 0;
	for (int i = 0; i < n; i++) {
		res += (pow(i,2)*pow(x, i))/(2*i+1);
	}
	return res;
}

double Y(double x) {
	if (x <= 0.) {
		printf("Expection raised!\n");
		return 0;
	}
	return ((1. / 4.) * (((x + 1) / sqrt(x)) * (sinh(sqrt(x)) - cosh(sqrt(x)))));
}

double func(double x) {
	return (fabs(Y(x) - S(x)));
}
