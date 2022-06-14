#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
    int N=1, K=1, L=1, sum=0;

    printf(("Enter N, K, L: "));
    scanf("%d%d%d", &N, &K, &L);

    if(K>L || L>N || L<0 || K<0 || N<=0){
        printf("Error\n");
        exit(-1);
    }

    int A[N];

    printf("\n");
    for(int i=1;i<=N;i++){
        printf("Enter the number[%d]: ", i);
        scanf("%d", &A[i]);
    }
    printf("\n");

    for(int i=K;i<=L;i++) sum += A[i];

    printf("\nSum = %d\n", sum);
    return 0;
}

