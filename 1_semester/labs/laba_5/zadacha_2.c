#include <stdio.h>

int main(int argc, char* argv[]){
    float a,b, r;
    printf("Enter two numbers: ");
    scanf("%f%f", &a, &b);


    if(a<b) r = b/a+1;
    else if(a==b) r = 25;
	else if(a>b) r = (b*b*b-5)/b;
    printf("%.3f\n", r);
}

