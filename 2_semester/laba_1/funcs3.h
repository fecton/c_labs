#pragma once
#include <stdio.h>


const int 
    apartments_at_floor = 7,
    floor_count = 14,
    apartments_at_entrance = 98;


// backend functions
int get_room_number(int apartment_number){
    unsigned int room_number = apartment_number % 10;

    return (room_number > apartments_at_floor) ? room_number - apartments_at_floor : room_number;
}

int get_entrance(int apartment_number){
    int 
    entrance_1 = apartments_at_entrance,
    entrance_2 = apartments_at_entrance*2,
    entrance_3 = apartments_at_entrance*3;

    int entrance_number = 0;
    if(apartment_number > 0 && apartment_number <= entrance_3){
        if(apartment_number <= entrance_1)  entrance_number = 1;
        else
        if(apartment_number <= entrance_2)  entrance_number = 2;
        else
        if(apartment_number <= entrance_3)  entrance_number = 3;
    }

    return entrance_number; 
}

int get_floor(int apartment_number){
    apartment_number = ((apartment_number/apartments_at_floor)+1)%floor_count;

    return apartment_number;
}

int get_room_count(int apartment_number){
    int room_number = get_room_number(apartment_number);
    int room_count = 0;

    switch(room_number){
        case 1:
        case 3:
            room_count = 8;
            break;
        case 2:
            room_count = 9;
            break;
        case 4:
        case 5:
        case 6:
        case 7:
            room_count = 6;
            break;
        default:
            break;  
    }

    return room_count;
}

int get_loggia_count(int apartment_number){
    int room_number = get_room_number(apartment_number);

    int loggia_count = (room_number == 1) ? 2: 1;

    return loggia_count;
}


// interface functions
void check_entrance(int apartment_number){
    int entrance_number = get_entrance(apartment_number);

    printf("\t * Entrance number: %3d\n", entrance_number);
}

void check_floor(int apartment_number){
    printf("\t * Floor: %13d\n", get_floor(apartment_number));
}

void check_room_count(int apartment_number){
    int room_number = get_room_count(apartment_number);
    printf("\t * Room count: %8d\n", room_number);
}

void check_loggia_count(int apartment_number){
    int loggia_count = get_loggia_count(apartment_number);
    printf("\t * Loggia count: %6d\n", loggia_count);
}
