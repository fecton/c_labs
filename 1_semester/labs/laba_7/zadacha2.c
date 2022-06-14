#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    double a,S=0,N;
    int i=1;

    printf("Enter a, N: ");
    scanf("%lf%lf", &a, &N);

    if(a == 0){
        printf("ERROR: Division by ZERO");
        exit(-1);
    }

    while(i<=N){
        S += 1/pow(a,i);   
        i++;
    }

    printf("Summ = %.2lf\n", S);

    return 0;
}

