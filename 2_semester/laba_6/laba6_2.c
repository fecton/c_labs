#include "laba6_2.h"
#include <stdio.h>

/*
	* У рядку str замінює цифри на латинські літери з відповідним номером у алфавіті (1-А, 2-В,..., 9-I, 0-J)
	*
	* @param str рядок
	* return кількість замінених цифр
*/
int encode_digits(char* str);

int main(int argc, char* argv[]) {

	char input[100];
	int a;

	printf("Enter string: ");
	scanf("%s", input);

	a = encode_digits(input);

	printf("\nResult: %s", input);
	printf("\nReturned code: %d", a);

	return 0;
}
