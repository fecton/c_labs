#include <stdio.h>
#include <math.h>
#include <locale.h>

#define pi 3.1415926

int main(void){
  setlocale(LC_CTYPE, "rus");
  float A, B, C, R, a, b, c;

  printf("Вводите углы в градусах!\n\n");
  printf("Введите угол альфа: ");
  scanf("%f", &A);
  printf("Введите угол бета: ");
  scanf("%f", &B);
  printf("Введите угол гамма: ");
  scanf("%f", &C);
  printf("Введите угол радуис описанного круга: ");
  scanf("%f", &R);
 
  if(A <= 0 || B <= 0 ||
     C <= 0 || R <= 0 || 
     (A+B+C != 180)
  ){
    printf("0\n");
    return 1;
  }
  
  A = A*pi/180;
  B = B*pi/180;
  C = C*pi/180;
  
  a = 2*R*sin(A);
  b = 2*R*sin(B);
  c = 2*R*sin(C);
  
  printf("\n%f см.\n", a);
  printf("%f см.\n", b);
  printf("%f см.\n", c);
  return 0;
}
