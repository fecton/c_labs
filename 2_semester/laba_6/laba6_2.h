/*
	* � ����� str ������ ����� �� �������� ����� � ��������� ������� � ������ (1-�, 2-�,..., 9-I, 0-J)
	* 
	* @param str �����
	* return ������� �������� ����
*/
int encode_digits(char* str) {
	int n;
	int count = 0;
	while(*str != '\0') {
		n = *str;
		if (n >= 49 && n <= 58) {
			*str = (char) (n + 16);
			count++;
		}
		str++;
	}
	return count;
}
