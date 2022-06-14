int nominals[6] = { 50, 25, 10, 5, 2, 1 };
int nominals_count[6] = { 0,0,0,0,0,0 };

/*
	* ������� ��������� �� ������� ����� �������� 50,25,10,5,2,1 �������
	* � ������� ���� � �������
	* 
	* @param sum ���� ��� ������� ������� �� ������
	* @param pointer ��������, � ���� ���������� ���������
	* return start_pointer ��������, ���� ����� �� ������� ��� �����
*/
void convert_coins(int sum, int* pointer) {
	int* start_pointer = pointer;

	for (int i = 0; i < 6; ++i) {

		if (sum >= nominals[i]) {
			*pointer = sum / nominals[i];
			sum %= nominals[i];
		}

		pointer++;
	}
}

