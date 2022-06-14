#include <stdio.h>

int main(int argc, char const *argv[])
{
    int A,B,N=2;

    printf("Enter A: ");
    scanf("%d", &A);

    printf("Enter B: ");
    scanf("%d", &B);

    printf("Enter N: ");
    scanf("%d", &N);

    if(N<2) return -1;

    int arr[N];
    arr[0] = A;
    arr[1] = B;

    for(int i=2;i<N;i++){
        arr[i] = 0;
	for(int j=0;j<i;j++){arr[i] += arr[j]; printf("%d\n", arr[i]);}
    }

    for(int i=0;i<N;i++) printf("%d ", arr[i]);
    printf("\n");

    return 0;
}

