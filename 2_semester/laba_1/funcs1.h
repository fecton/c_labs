#pragma once
#include <stdio.h>

int compare(double megabytes, double kilobytes){
    unsigned long 
        megabytes_in_bytes = megabytes * 1024 * 1024,
        kilobytes_in_bytes = kilobytes * 1024;

    if(megabytes > 0 && kilobytes > 0){
        if(megabytes_in_bytes > kilobytes_in_bytes){
            printf("\t[>] MB is bigger than KB\n\t%.2lf MB > %.2lf KB\n", megabytes, kilobytes);
            return 1;
        }
        else{
            if(megabytes_in_bytes == kilobytes_in_bytes){
                printf("\t[=] KB is equals MB\n\t%.2lf KB = %.2lf MB\n", kilobytes, megabytes);
                return 0;
            }
            else{
                printf("\t[<] KB is bigger than MB\n\t%.2lf KB > %.2lf MB\n", kilobytes, megabytes);
                return -1;
            }
        }
    }

    printf("\t [-] ERROR: wrong input!");
    return 100;
}
