#include <stdlib.h>
#include <time.h>
#include <stdio.h>


int split(int a[], int low, int high) {
    int part_element = a[low];
    for (;;) {
        while (low < high && part_element <= a[high]) high--;
        if (low >= high) break;
        a[low++] = a[high];
        while (low < high && a[low] <= part_element) low++;
        if (low >= high) break;
        a[high--] = a[low];
    }
    a[high] = part_element;
    return high;
}

void quicksort(int a[], int low, int high) {
    int middle;
    if (low >= high) return;
    middle = split(a, low, high);
    quicksort(a, low, middle - 1);
    quicksort(a, middle + 1, high);
}

void printArr(int array[], int length) {
    for (int i = 0; i < length; ++i) {
        printf(" %d", array[i]);
    }
    printf("\n");
}

void randomArr(int array[], int length) {
    srand((unsigned)time(NULL));
    for (int i = 0; i < length; ++i) {
        array[i] = rand() % 250;
        if (rand() % 2 == 1) array[i] *= -1;
    }
}

void enterArr(int array[], int length) {
    for (int i = 0; i < length; ++i) {
        printf("Введите array[%d]: ", i + 1);
        scanf("%d", &array[i]);
        printf("\n");
    }
}
