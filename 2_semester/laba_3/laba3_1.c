#include "laba3_1.h"

int main(int argc, const char* argv[]) {
	long n;

	setlocale(LC_ALL, "Ukr");

	printf("¬вед≥ть число: ");
	scanf("%ld", &n);

	check_repeated_digits(n);

	return 0;
}
