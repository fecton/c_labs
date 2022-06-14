#include "funcs3.h"

int main(int argc, const char* argv[]){
    int apartment_number;

    printf("Enter an apartment number: ");
    scanf("%d", &apartment_number);

    if(!get_entrance(apartment_number)){
        printf("\t [-] Bad apartment number!");
        return -1;
    }

    printf("\t ========= By Fecton =========\n");
    printf("\t * House serial: 1-528KP-80EK\n");
    check_entrance    (apartment_number);
    check_floor       (apartment_number);
    check_room_count  (apartment_number);
    check_loggia_count(apartment_number);
    printf("\t =============================\n");

    return 0;
}
