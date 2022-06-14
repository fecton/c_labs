#include <stdio.h>
#include <iso646.h>
#include <stdbool.h>
#define N 6

void parray(int A[]){
    for(int i=0;i<N;++i) printf(" %3d ", A[i]);
    printf("\n");
}

int main(int argc, char const *argv[])
{
    unsigned int A[N] = {4, 115, 7, 195, 25, 106};
    unsigned int count=1;

    parray(A);

    for (unsigned int i = 0; i < N; i++)
    {
        if(A[i]>100 and A[i]%5==0){
            A[i] = count;
            count=1;
        } 
        else count++;
    }
    
    parray(A);


    return 0;
}

