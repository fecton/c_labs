#include <stdbool.h>
#include <stdio.h>
#include <iso646.h>

#define N 6

int main(int argc, char const *argv[])
{
    int A[N] = {0};

    for(int i=0;i<N;++i){
        A[N-i-1] = i;
    }

    for(int i=0;i<N;++i){
        printf(" %d ", A[i]);
    }

    return 0;
}
