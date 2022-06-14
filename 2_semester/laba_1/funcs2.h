#pragma once

#include <stdio.h>
#include <math.h>
#include <string.h>

int lower_or_upper(unsigned int seat_number){
    /*
    Returns 0 if it is mod
    else if returns 1
    */
    if(seat_number%2 == 0){
        printf("\t* Upper shelf\n");
        return 0;
    }
    else{
        printf("\t* Lower shelf\n");
        return 1;
    }
}

int kype_number(unsigned int seat_number){
    /*
    Returns kype_number by seat_number
    */
    return (seat_number > 36) ? ceil((19-(seat_number-36))/2.f) : ceil(seat_number/4.f);
}

int roman_kype_number(unsigned int seat_number){
    /*
    If coupe returns 0
    If side place    1
    */
    char roman_number[5];
    switch(kype_number(seat_number)){
        case 1:
            strcpy(roman_number, "I");
            break;
        case 2:
            strcpy(roman_number, "II");
            break;
        case 3:
            strcpy(roman_number, "III");
            break;
        case 4:
            strcpy(roman_number, "IV");
            break;
        case 5:
            strcpy(roman_number, "V");
            break;
        case 6:
            strcpy(roman_number, "VI");
            break;
        case 7:
            strcpy(roman_number, "VII");
            break;
        case 8:
            strcpy(roman_number, "VIII");
            break;
        case 9:
            strcpy(roman_number, "IX");
            break;
        default:
            strcpy(roman_number, "err");
            break;
    }

    if(seat_number > 36){
        printf("\t* Side place %s\n", roman_number);
        return 1;
    }
    else{
        printf("\t* Coupe %s\n", roman_number);
        return 0;
    }
}

int length_to_toilet(unsigned int seat_number){
    // Returns total_length
    
    unsigned int 
        knumber = kype_number(seat_number),
        total_length,
        conductor_length = 1;      

    total_length = (knumber < 5) ? (knumber-1)*2 + conductor_length : (9 - knumber)*2;
    
    printf("\t* Length is %d m.\n", total_length);

    return total_length;
}
