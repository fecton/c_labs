#include "laba6_2.h"
#include <stdio.h>

/*
	* � ����� str ������ ����� �� �������� ����� � ��������� ������� � ������ (1-�, 2-�,..., 9-I, 0-J)
	*
	* @param str �����
	* return ������� �������� ����
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
