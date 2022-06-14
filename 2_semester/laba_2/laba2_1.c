#include "laba2_1.h"

int main(int argc, const char* argv[]) {
	printf("| X | Y(x) | S(x) | |Y(x) - S(x)| |\n\n");
	for (double x = a; x < b; x += (b - a) / n) {
		printf("|%.3lf|%.3lf|%.3lf|%.3lf|\n", x, Y(x), S(x), func(x));
	}
	printf("\n");

	double x = 0;
	printf("Enter x: ");
	scanf("%lf", &x);

	printf("\nX  Y(x)  S(x)  |Y(x)-S(x)|\n%.3lf  %.3lf  %.3lf  %.3lf\n\n", x, Y(x), S(x), func(x));

	return 0;
}
