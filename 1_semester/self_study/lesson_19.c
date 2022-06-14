#include <stdio.h>
#define N 5

void parray(int A[]){
    for(int i=0;i<N;++i) printf(" %3d ", A[i]);
    printf("\n");
}

// TODO: Print array
// TODO: Reverse array and print it
// TODO: shift array to left and print it
// TODO: shift array to right and print it

int main(int argc, char const *argv[])
{
    int A[N] = {10, 20, 30, 40, 50};
    int tmp=0, tmp2=0;

    printf("Array A:   ");
    parray(A);

    for(int i=0; i<N/2; ++i){
        tmp = A[N-i-1];
        A[N-i-1] = A[i];
        A[i] = tmp;
    }
    printf("Reversed A:");
    parray(A);

    tmp = A[0];
    for (int i = 0; i < N-1; i++)
    {
        // tmp2 = A[i-1];
        A[i] = A[i+1];
    }
    A[N-1]=tmp;
    printf("LeftShft A:");
    parray(A);
    

    int B[N] = {50, 40, 30, 20, 10};

    tmp = B[N-1];
    for (int i = N-1; i > 0; --i)
    {
        B[i] = B[i-1];
    }
    B[0] = tmp;
    printf("RghtShft B:");
    parray(B);
    return 0;
}
