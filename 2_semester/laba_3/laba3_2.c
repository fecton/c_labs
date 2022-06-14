#include "laba3_2.h"

int main(int argc, const char* argv[]) {
	int n = 0, choice = 0;
	printf("Enter N: ");
	scanf("%d", &n);

	int array[100] = { 0, };

	printf("Would you like to random or enter? (0/1): ");
	scanf("%d", &choice);

	if (choice) {
		for (int i = 0; i < n; ++i) {
			printf("Enter array[%d]: ", i);
			scanf("%d", &array[i]);
		}
	}
	else
	{
		srand((unsigned)time(NULL));
		for (int i = 0; i < n; ++i) {
			array[i] = rand() % 100;
			if (rand() % 2 == 1) array[i] *= -1;
		}
	}

	for (int i = 0; i < n; ++i) {
		printf("%d ", array[i]);
	}

	printf("Sum: %d", get_sum(array, n));

}
