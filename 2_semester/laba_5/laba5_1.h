int nominals[6] = { 50, 25, 10, 5, 2, 1 };
int nominals_count[6] = { 0,0,0,0,0,0 };

/*
	* Повертає вказівники на кількість монет номіналом 50,25,10,5,2,1 копійках
	* з вказаної суми в копійках
	* 
	* @param sum суму яку потрібно розбити на монети
	* @param pointer вказівник, в який записується результат
	* return start_pointer вказівник, який вказує на кількість всіх монет
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

