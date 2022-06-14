#include "sds.h"

/*
	* Эта функция может не работать в IDE Visual Studio 2022, желательно использовать компилятор gcc
	* У рядку str замінює цифри на латинські літери з відповідним номером у алфавіті (1-А, 2-В,..., 9-I, 0-J)
	*
	* @param str рядок
	* return кількість замінених цифр
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
