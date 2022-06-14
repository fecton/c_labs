#include "sds.h"

/*
	* ��� ������� ����� �� �������� � IDE Visual Studio 2022, ���������� ������������ ���������� gcc
	* � ����� str ������ ����� �� �������� ����� � ��������� ������� � ������ (1-�, 2-�,..., 9-I, 0-J)
	*
	* @param str �����
	* return ������� �������� ����
*/
sds encode_digits3(char* str) {
	sds string = sdsnew(str);
	int count = 0;
	int n;
	for (int i = 0; i < sdslen(string); ++i) {
		n = (int) string[i];
		if (n >= 49 && n <= 58) {
			string[i] = (char) (n + 16);
			count++;
		}
	}

	return string;
}
