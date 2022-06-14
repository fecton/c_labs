#include "funcs1.h"

int main(int argc, const char argv[]){
    double 
        megabytes, 
        kilobytes;
    
    megabytes = kilobytes = -1.0;
    
    printf("\t[?] 1 MB = 1024 KB\n\t[?] 1 KB = 1024 B\n\n");
    printf("Enter MB and KB: ");
    scanf("%lf%lf", &megabytes, &kilobytes);

    compare(megabytes, kilobytes);                           

    return 0;
}

