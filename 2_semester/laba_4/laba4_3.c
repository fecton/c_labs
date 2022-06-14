#include "laba4_3.h"

/*
	* Функція повертає значення кута напроти катета а
	* Вхідні дані: катети a, b
	* Вихідні дані: кут напроти катета a
*/
double angle(double a, double b);

int main() {
	double a, b;
	printf("Enter a,b: ");
	scanf("%lf%lf", &a, &b);

	printf("%lf", (angle(a, b) * 180) / M_PI);

	return 0;
}
