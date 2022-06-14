#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define pi 3.14

int main(int argc, char const *argv[])
{
    float value;
    float R=0., D=0., L=0., S=0.;
    char choice;

    printf("Enter choice and value: ");
    scanf("%hd%f", &choice, &value);

    switch(choice){
        case(1): { // R
            R = value;
            D = 2*R;
            L = D*pi;
            S = pi*R*R;
            break;
        };
        case(2): { // D
            D = value;
            R = 0.5*D;
            L = D*pi;
            S = pi*R*R;
            break;
        };
        case(3): { // L
            L = value;
            R = L / (2*pi);
            D = 2*R;
            S = pi*R*R;
            break;
        };
        case(4): { // S
            S = value;
            R = sqrt(S/pi);
            D = 2*R;
            L = D*pi;
            break;
        };
        default: {
            printf("No choice\n"); 
            exit(-1); 
        }
    }

    printf("R = %.2f\n", R);
    printf("D = %.2f\n", D);
    printf("L = %.2f\n", L);
    printf("S = %.2f\n", S);

    return 0;
}
