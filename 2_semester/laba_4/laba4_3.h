#include <math.h>
#include <stdio.h>

#define M_PI 3.1415926535897932384626433832795

double angle(double a, double b) {
	/*
		  |\
		a | \ 
		  |  \ A
		  -----
		    b
		Input  double: a, b - катети
		Return double: кут A навпроти катета a
	*/

	return round(atan(a / b) * 180 / M_PI);
}
