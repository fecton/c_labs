#include <stdio.h>

int main(int argc, char* args[])
{
    int a,b,c;
    a=b=c=0;

    printf("Enter numbers: ");
    scanf("%d%d%d", &a, &b, &c);

    if(a==b && c==a) printf("%d\n", a);

    if((c<a && a<b) || (b<a && a<c))          printf("%d\n", a); // c<a<b and b<a<c
    else if((c<b && b<a) || (a<b && b<c))     printf("%d\n", b); // c<b<a and a<b<c
        else if((a<c && c<b) || (b<c && c<a)) printf("%d\n", c); // a<c<b and b<c<a
        
    return 0;
}
