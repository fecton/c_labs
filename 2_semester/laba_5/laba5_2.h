#include <stdio.h>

/*
	* Порівнює значення елементів масиву з константами
	*
	* @param arrPtr вказівник на одновимірний масив
	* @param countsPtr вказівник на масив з кількостями
	* @param N розмірність масиву
	* Увесь результат записується через вказівник sortedPtr
*/
void compare_count(int* arrPtr, int* countsPtr, int N) {
	for (int i = 0; i < N; ++i) {
		if (*arrPtr >= 0 && *arrPtr <= 100) {
			(*countsPtr)++;
		}
		else if (*arrPtr >= 101 && *arrPtr <= 200) {
			(*(countsPtr + 1))++;
		}
		arrPtr++;
	}
}
