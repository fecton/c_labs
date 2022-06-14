#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int n = 7;

int get_sum_12(int matrix[n][n]) {
    int total_sum = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%4d ", matrix[i][j]);
            if (
                ((i + 1) % 2 == 1 && (j + 1) % 2 == 1)
                ||
                ((i + 1) % 2 == 0 && (j + 1) % 2 == 0)
                ) {
                total_sum += matrix[i][j];
            }
        }
        printf("\n");
    }

    printf("\nSum: %d\n", total_sum);
    return total_sum;
}

int determinant(int matrix[n][n]) {
    int det = 0;
    int md[3][3] = {
        {matrix[2][0], matrix[2][1], matrix[2][2]},
        {matrix[3][0], matrix[3][1], matrix[3][2]},
        {matrix[4][0], matrix[4][1], matrix[4][2]},
    };

    det = (
            md[0][0]*md[1][1]*md[2][2] +
            md[2][0]*md[0][1]*md[1][2] +
            md[1][0]*md[2][1]*md[0][2] -
        
            md[2][0]*md[1][1]*md[0][2] -
            md[0][0]*md[2][1]*md[1][2] -
            md[1][0]*md[0][1]*md[2][2]
        );

    printf("det = %d\n", det);

    return det;
}

