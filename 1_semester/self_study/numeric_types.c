#include <stdio.h>

char numeric_number_16(int number){
    switch (number)
    {
        case 10: return 'A';
        case 11: return 'B';  
        case 12: return 'C';
        case 13: return 'D';
        case 14: return 'E';
        case 15: return 'F';
    }
}


int main(void){
    unsigned short NS=10, number=0, i=1, j=0, j_temp=0, i_temp=0, div_res=0;

    unsigned short array[64];
    char output[64];

    // printf("Numeric system (default 10): "); scanf("%hu", &NS);
    // printf("Your number: "); scanf("%hu", &number);

    number = 10;
    NS = 2;

    if(NS > 16){
        printf("Sorry, this numeric system doesn't supported :(\n");
        return 1;
    }

    while(1){
        div_res = number % NS;
        number = number / NS;
        array[i] = div_res;
        if(number == 0) break;
        i++;
    }

    i_temp = i;

    if(NS == 2){
        i = i_temp;
        printf("===%d\n", i);
        while(i%3) i++;
        printf("===%d\n", i);
        j = i_temp - i;
        j_temp = j;

        for(i=i_temp;i>0;i--){
            if(j%3==0 && j!=0) printf(" ");
            if(array[i] > 10) printf("%c", numeric_number_16(array[i]));
            else              printf("%d", array[i]);
            j++;
        }
        printf("\n\n");


        i = i_temp;
        printf("%d\n", i);
        while(i%3) i++;
        printf("%d\n", i);

        j = i_temp - i;
        j_temp = j;

        for(i=i_temp;i>0;i--){
            if(j%4==0 && j!=0) printf(" ");
            if(array[i] > 10) printf("%c", numeric_number_16(array[i]));
            else              printf("%d", array[i]);
            j++;
        }
    }
    else{
        for(i=i_temp;i>0;i--){
            if(array[i] > 10) printf("%c", numeric_number_16(array[i]));
            else              printf("%d", array[i]);
        }
    }
    printf("\n");

    return 0;
}
