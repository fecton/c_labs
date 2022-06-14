#include <stdio.h>
#include <math.h>

/*
	* Знаходження однакових трикутників у матриці
	*
	* @param m вказівник на перший елемент матриці
	* @param n розмірність матриці
	* return 1, якщо трикутники рівні
	* інакше 0
*/
int check_triangles(int* m, int n) {
	int triangle1 = 0, triangle2 = 0;
	int* end_pointer;
	int indicator = 0;

	if (n % 2 != 0) {
		int middle = ceil(n / 2.);
		for (int i = 1; i < n + 1; i++) {
			m += indicator;

			end_pointer = m + n - (indicator * 2);

			for (m; m < end_pointer; m++) {
				if (i < middle)
					triangle1 += *m;
				else if (i == middle) {
					triangle1 += *m;
					triangle2 += *m;
				}
				else
					triangle2 += *m;
			}
			m += indicator;
			if (i < middle)
				indicator++;
			else
				indicator--;
		}
	}
	else {
		int middle = n / 2;
		for (int i = 1; i < n + 1; i++) {
			m += indicator;

			end_pointer = m + n - (indicator * 2);

			for (m; m < end_pointer; m++) {
				if (i <= middle)
					triangle1 += *m;
				else
					triangle2 += *m;
			}
			m += indicator;
			if (i < middle)
				indicator++;
			else
				if (indicator != 0) indicator--;
		}
	}



	if (triangle1 == triangle2) {
		return 1;
	}

	return 0;
}
