#include "laba3_3.h"

int main(int argc, char const* argv[])
{
    int choice = 0, negative = 0;
    int matrix[n][n] = { {0,}, };

    printf("Would you line to random it or enter? (0/1): ");
    scanf_s("%d", &choice);

    printf("\n");
    // user choice RANDOM/INPUT
    if (choice == 1) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                printf("Enter matrix[%d][%d]: ", i + 1, j + 1);
                scanf_s("%d", &matrix[i][j]);
            }
            printf("\n");
        }
    }
    else {
        srand((unsigned)time(NULL));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                negative = rand() % 2;
                matrix[i][j] = rand() % 251;
                if (negative == 1) matrix[i][j] *= -1;
            }
        }
    }

    get_sum_12(matrix);
    determinant(matrix);

    return 0;
}
