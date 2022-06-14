#include <stdio.h>
#include "laba5_1.h"

/*
	* ������� ��������� �� ������� ����� �������� 50,25,10,5,2,1 �������
	* � ������� ���� � �������
	*
	* @param sum ���� ��� ������� ������� �� ������
	* @param pointer ��������, � ���� ���������� ���������
	* return start_pointer ��������, ���� ����� �� ������� ��� �����
*/
void convert_coins(int sum, int* pointer);

int main() {
	int* pointer = &nominals_count[0];
	int sum;
	printf("Enter the sum: ");
	scanf("%d", &sum);
	
	if (sum < 0) {
		printf("[!!] Invalid number!\n");
		return -1;
	}

	convert_coins(sum, pointer);

	printf("-=-=-=-=[ Counts ]=-=-=-=-=-\n");
	for (int i = 0; i < 6; ++i) {
		printf("\t%3d:  %3d\n", nominals[i], *pointer);
		pointer++;
	}
	printf("-=-=-=-=-=-=-=-=-==-=-=-=-=-\n");
	return 0;
}

