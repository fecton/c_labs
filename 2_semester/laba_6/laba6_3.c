#include "laba6_3.h"
#include <stdio.h>

/*
	* �� ������� ���� �� ��������� ��������� � IDE VS 2022
	* � ����� str ������ ����� �� �������� ����� � ��������� ������� � ������ (1-�, 2-�,..., 9-I, 0-J)
	*
	* @param str �����
	* return ���������� ����� 
*/
sds encode_digits3(char* str);

int main() {
	char input[100];
	printf("[ WARNING! ]\n");
	printf("Enter string without spaces\n");
	printf("Thank you! <3\n");
	printf("---------------------\n");
	
	printf("Str: ");
	scanf("%s", input);

	sds str_before = sdsnew(input);
	sds str_after = encode_digits3(input);

	printf("Before: %s\n", str_before);
	printf("After : %s\n", str_after);

	return 0;
}
