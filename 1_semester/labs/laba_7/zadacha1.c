#include <stdio.h>

int main(int argc, char const *argv[])
{
    int N, sum=0;
    
    printf("Enter N: ");
    scanf("%d", &N);

    for(int i=1;i<=N;i++)
        if(i%2==0) sum += i;

    printf("%d", sum);

    return 0;
}

