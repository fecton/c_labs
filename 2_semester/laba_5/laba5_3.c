#include "laba5_3.h"

/*
	* Знаходження однакових трикутників у матриці
	*
	* @param m вказівник на перший елемент матриці
	* @param n розмірність матриці
	* return 1, якщо трикутники рівні
	* інакше 0
*/
int check_triangles(int* m, int n);

int main() {
	int N;
	int* mpointer;

	// reading length
	printf("Enter N: ");
	scanf("%d", &N);

	// in visual studio 2022 it could raise an error
	// bcz a variable can't use as a constant :(
	int matrix[N][N];

	// reading matrix
	int i = 1, j = 1;
	for (mpointer = &matrix[0][0]; mpointer < &matrix[N - 1][N]; mpointer++) {
		if (j % (N+1) == 0) {
			j = 1;
			i++;
			printf("\n");
		}
		printf("Enter matrix[%d][%d]: ", i, j);
		scanf("%d", mpointer);
		j++;
	}

	// do some magic and print result <3
	printf("%d\n", check_triangles(&matrix[0][0], N));

}
