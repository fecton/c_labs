
#include <stdio.h>
#include <locale.h>
#include <math.h>
#define pi 3.1415926

int main(void){
    setlocale(LC_CTYPE, "rus");

    float a, z1, z2, t;

    printf("Введите угол α: ");
    scanf("%f", &a);

    z1 = ( sin(4*a) / (1+cos(4*a)) ) * ( cos(2*a) / (1+cos(2*a)) ); 
    z2 = 1/tan( (3/2)*pi - a );

    printf("Z1 = %.8e\n", z1);
    printf("Z2 = %.8e\n", z2);

    return 0;
}


