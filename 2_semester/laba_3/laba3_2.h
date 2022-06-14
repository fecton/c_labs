#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int get_sum(int* array, int n) {
	int first = 0;
	int total_sum = 0;

	for (int i = 0; i < n; ++i) {
		if (array[i] > 0 && first == 0) {
			first = 1;
			continue;
		}
		else {
			if (array[i] > 0) {
				total_sum += array[i];
			}
			else {
				first = 0;
				continue;
			}
		}
	}
	return total_sum;
}
