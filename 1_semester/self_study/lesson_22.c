#include <stdio.h>
#define N 5

int main(int argc, char const *argv[])
{
    short A[N] = {4,2,6,13,39};

    for (short i = 0; i < N; i++)
    {
        if((A[i]*A[j])%26==0) printf("%hd*%hd = %hd\n", A[i], A[j], A[i]*A[j]);
    }
    


    return 0;
}


