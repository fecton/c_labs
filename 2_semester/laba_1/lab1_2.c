#include "funcs2.h"

int main(int argc, const char argv[]){
    unsigned int seat_number;

    printf("Enter a desirable seat place: ");
    scanf("%d", &seat_number);

    if(!(seat_number > 0 && seat_number < 55)){
        printf("\t[-] This seat doesn't exist!");
        return -1;
    }

    lower_or_upper   (seat_number);
    roman_kype_number(seat_number);
    length_to_toilet (seat_number);

    return 0;
}

