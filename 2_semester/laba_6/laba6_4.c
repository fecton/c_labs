#include "laba6_4.h"
#include <stdio.h>

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
int show_table(int argc, char* argv[]);

int main(int argc, char* argv[]) {

	show_table(argc, argv);

	return 0;
}
