#include <stdio.h>
#include <math.h>

const double M_PI = 3.1415926535897932384626433832795;

int flag = 1;
double global = 0;

void show_menu() {
	printf("  ---  By Fecton --- \n");
	printf(" =====================\n");
	printf("  0. Reset\n");
	printf("  1. Add\n");
	printf("  2. Sub\n");
	printf("  3. Multiply\n");
	printf("  4. Divide\n");
	printf("  5. tg(x)\n");
	printf("  6. |x|\n");
	printf("  7. sqrt3(x)\n");
	printf("  8. Show this menu\n");
	printf("  9. Exit\n");
	printf(" =====================\n");
}

double reset() {
	global = 0;
	return 0;
}

double add(double a, double b) {
	global = a + b;
	printf("%.3lf + %.3lf = %.3lf\n", a, b, global);
	return global;
}

double sub(double a, double b) {
	global = a - b;
	printf("%.3lf - %.3lf = %.3lf\n", a, b, global);
	return global;
}

double mul(double a, double b) {
	global = a * b;
	printf("%.3lf * %.3lf = %.3lf\n", a, b, global);
	return global;
}

double divide(double a, double b) {
	global = a / b;
	printf("%.3lf / %.3lf = %.3lf\n", a, b, global);
	return global;
}

double tangence(double a) {
	double result = tan((a * M_PI) / 180.0);
	printf("tg(%.3lf) = %.3lf\n", a, result);
	return result;
}

double modul(double a) {
	double modul = fabs(a);
	printf("|%.3lf| = %.3lf\n", a, modul);
	return modul;
}

double sqrt3(double a) {
	double sqrt3 = pow(a, (1. / 3.));

	if (a < 0) {
		printf("sqrt3(%.3lf) = None\n", a);
		return 0;
	}
	else {
		printf("sqrt3(%.3lf) = %.3lf\n", a, sqrt3);
		return sqrt3;
	}
}

void select_action(int user_input) {
	// no argument
	switch (user_input) {
		case 0:
			reset();
			return;
		case 8:
			show_menu();
			return;
		case 9:
			flag = 0;
			return;
		default: break;
	}

	double 
		a = 0,
		b = 0;

	if (global == 0) {
		printf("Enter FIRST number: ");
		scanf("%lf", &a);
	}
	else {
		a = global;
	}

	// one argument
	switch (user_input) {
		case 5: // tg(a)
			tangence(a);
			return;
		case 6: // |a|
			modul(a);
			return;
		case 7: // sqrt3(a)
			sqrt3(a);
			return;
		default: break;
	}

	printf("Enter SECOND number: ");
	scanf("%lf", &b);

	// two arguments
	switch (user_input) {
		case 1: // a + b
			add(a, b);
			break;
		case 2: // a - b
			sub(a, b);
			break;
		case 3: // a * b
			mul(a, b);
			break;
		case 4: // a / b
			divide(a, b);
			break;
		default: // show message error
			printf("[-] Incorrect operation!\n");
			break;
	}
}

int calculator() {
	int user_input;

	show_menu();

	while (flag) {
		printf("\n[?] Operation: ");
		scanf("%d", &user_input);
		select_action(user_input);
	}

	return 0;
}

