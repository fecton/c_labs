#include "laba4_3.h"

/*
	* ������� ������� �������� ���� ������� ������ �
	* ����� ���: ������ a, b
	* ������ ���: ��� ������� ������ a
*/
double angle(double a, double b);

int main() {
	double a, b;
	printf("Enter a,b: ");
	scanf("%lf%lf", &a, &b);

	printf("%lf", (angle(a, b) * 180) / M_PI);

	return 0;
}
