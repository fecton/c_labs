#include "laba6_3.h"
#include <stdio.h>
#include <string.h>

/*
    * Програма виводить таблицю, рядки якої містять
    * параметри командного рядка
    * змінений рядок
    * повернене значення функції
    * 
    * @param argc кількість аргументів
    * @param argv аргументи
    * 
    * return -1, якщо аргументи пусті та 0, якщо вони є
*/
int show_table(int argc, char* argv[]) {
    char input[100];
    sds res = 0;

    if (argc == 1) {
        printf("\nEnter a string:");
        scanf("%s", input);

        res = encode_digits3(&input[0]);
        printf("\n| %15s | %15s |\n", input, res);
    }
    else if (!strcmp(argv[1], "/?") || !strcmp(argv[1], "-?")) {
        printf("This is a help message\n");
        printf("For using this function\n");
        printf("You need to enter some value as a console argument\n");
        printf("First argument /? and -? calls this message\n");
    }
    else {
        printf("-=-=-=-=-=-=[ RESULTS ]=-=-=-=-=-=-\n");
        printf("-------------------------------------\n");
        printf("| %15s | %15s |\n", "INPUT", "OUTPUT");
        
        int i = 1;

        while (i < argc) {
            res = encode_digits3(argv[i]);
            printf("| %15s | %15s |\n", argv[i], res);
            i++;
        }

        printf("-------------------------------------\n");
        printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n\n");
    }


    return 0;
}
