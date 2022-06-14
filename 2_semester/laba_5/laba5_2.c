#include "laba5_2.h"

/*
	* ������� �������� �������� ������ � �����������
	*
	* @param arrPtr �������� �� ����������� �����
	* @param sortedPtr �������� �� ����� � ����������
	* @param N ��������� ������
	* ����� ��������� ���������� ����� �������� sortedPtr
*/
void compare_count(int* arrPtr, int* sortedPtr, int N);

int main() {
	int arr[100] = { 0, }, N, sorted[2] = { 0, };
	
	int *startArrPtr = &arr[0], *sortedPtr = &sorted[0];
	int* arr_ptr = startArrPtr;


	printf("Enter N: ");
	scanf("%d", &N);

	for (int i = 0; i < N; ++i) {
		printf("Enter arr[%3d]: ", i);
		scanf("%d", arr_ptr);
		arr_ptr++;
	}

	compare_count(startArrPtr, sortedPtr, N);

	printf("\n-=-=-=-=-=-=[ Results ]=-=-=-=-=-=-\n");
	printf("\t0 <= x <= 100\t%d\n", *sortedPtr);
	printf("\t101 <= x <= 200\t%d\n", *(++sortedPtr));

	return 0;
}

