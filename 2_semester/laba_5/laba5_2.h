#include <stdio.h>

/*
	* ������� �������� �������� ������ � �����������
	*
	* @param arrPtr �������� �� ����������� �����
	* @param countsPtr �������� �� ����� � ����������
	* @param N ��������� ������
	* ����� ��������� ���������� ����� �������� sortedPtr
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
