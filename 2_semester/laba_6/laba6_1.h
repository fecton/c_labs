#include <locale.h>
#include <stdio.h>

/*
	* Виводить моє ім'я використовуючи символи ASCII таблиці
*/
void print_my_name() {
	setlocale(LC_ALL, "866");
	printf("\x41\x6e\x64\x72\x65\x77\x20\x4c\x69\x74\x76\x69\x6e\x65\x6e\x6b\x6f\n");
}
