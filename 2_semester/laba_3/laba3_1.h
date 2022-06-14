#include <stdio.h>
#include <locale.h>

int check_repeated_digits(long n) {
	setlocale(LC_ALL, "Ukr");

	int is_repeated = 0;
	int digit_seen[10] = { 0, };
	int digit_count[10] = { 0, };
	int digit;

	while (n > 0) {
		digit = n % 10;
		if (digit_seen[digit]) {
			digit_count[digit] += 1;
			is_repeated = 1;
		}
		digit_seen[digit] = 1;
		
		if (digit_count[digit] == 0) {
			digit_count[digit] = 1;
		}

		n /= 10;
	}

	if (is_repeated) {
		printf("× צטפנט, שמ ןמגעמנ‏‏עüסÿ: ");
		for (int i = 0; i < 10; ++i) {
			if (digit_count[i] > 1) {
				printf("%d (%d נאחט) ", i, digit_count[i]);
			}
		}
		printf("\n");
		return 1;
	}
	else {
		printf("Íולא÷ צטפנ, שמ ןמגעמנ‏‏עüסÿ\n");
		return 0;
	}
}



