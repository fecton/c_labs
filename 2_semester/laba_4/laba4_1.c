#include "laba4_1.h"

int main() {
    int choice = 0, length = 0;
    int array[100] = { 0, };

    printf("Enter N: ");
    scanf("%d", &length);

    printf("Enter or random (0, 1): ");
    scanf("%d", &choice);

    if (choice) {
        randomArr(array, length);
    }
    else {
        enterArr(array, length);
    }
    printf("Unsorted array: ");
    printArr(array, length);

    printf("\nSorted array: ");
    quicksort(array, 0, length - 1);
    printArr(array, length);

    return 0;
}
