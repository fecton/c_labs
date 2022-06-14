#include <stdio.h>
int main(void){
    unsigned long long int A, i, j;
    printf("Введите число А: ");
    scanf("%lld", &A);
    i = A;
    j = A;
    printf("%lld^2 = %lld\n", A, A*i);
    
    i = i*j;
    printf("%lld^3 = %lld\n", A, A*i);
    
    i = i*j*j;
    printf("%lld^5 = %lld\n", A, A*i);
    
    i = i*j*j*j*j*j;
    printf("%lld^10 = %lld\n", A, A*i);
    
    i = i*j*j*j*j*j;
    printf("%lld^15 = %lld\n", A, A*i);
    
    return 0;
}

