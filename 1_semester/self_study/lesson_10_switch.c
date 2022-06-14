#include <stdio.h>

int main(int argc, char const *argv[])
{
    int x;
    scanf("%d", x);

    switch(x){
        case 1: printf("One!\n");
        case 2: printf("Two!\n");
        case 3: printf("Three!\n");
        case 0: printf("Zero!");
        default: printf("Don't know this number\n");
    };
    
    return 0;
}

