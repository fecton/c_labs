#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void print_arr(int arr[], int N){
    for(int i=0;i<N;i++) printf("%d ", arr[i]);
    printf("\n");
}

void rand_array(int arr[], int N){
    srand((unsigned) time(NULL));
    for(int i=0;i<N;i++) arr[i] = rand();
    return;
}

int main(int argc, char const *argv[])
{
    int N=5;
    int A[5] = {0};
    print_arr(A,N);
    
    rand_array(A, N);
    printf("\n");
    print_arr(A,N);
    
    return 0;
}



