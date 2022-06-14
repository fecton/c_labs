#include <stdio.h>

int main(int argc, char const *argv[])
{
    int N, sum=0, average, changed_count=0;

    printf("Enter N: ");
    scanf("%d", &N);

    if(N<=0) return -1;

    int A[N];

    for(int i=0;i<N;i++){
        printf("Enter A[%d]: ", i);
        scanf("%d", &A[i]);
        sum += A[i];
    }
    
    average = sum/N;

    printf("Average number: %d\n", average);

    for(int i=0;i<N;i++){
        if(A[i] < average*0.5 || A[i] > average*1.5){
            A[i] = 0;
            changed_count++;
        }
    }
    printf("The count of changed numbers: %d\n\n", changed_count);

    printf("My array:\n");
    for(int i=0;i<N;i++) printf("%d ", A[i]);
    printf("\n");

    return 0;
}

