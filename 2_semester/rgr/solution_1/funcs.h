#ifndef _LIBS_
#define _LIBS_
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#endif

/*
* Count symbols before \0
* 
* @param string pointer
* return count 
*/
int ccount(char* string, unsigned int method) {
	int count = 0;
	int i = 0;

	switch(method){
		case 1:
			for (int i = 0; i < sizeof(string); ++i) {
				if (string[i] != ' ' && string[i] != '\n') {
					if (string[i] == '\0') {
						break;
					}
					else {
						count++;
					}
				}
			}
		break;
		case 2:
			while(string[i] != '\n' && string[i] != '\0'){
				count++;
				i++;
			}
		break;
		default:
			return 0;
	}

	return count;
}

/*
* This function veryify the key from the config file
*
* @param key Key from the confg file
*/
// 01AFC567
int verify_key(char* key) {
	if (!(
		(key != NULL) &&
		(ccount(key, 2) == 8) &&
		(key[3] == 'F') &&
		(key[5] == '5'))) {
		printf("[!] ERROR: key is not valid you can change it in '10) Options'\n");
		return 1;
	}
	return 0;
}

/*
* Generates a random key
*/
char* generate_key(char* key) {
	srand(time(0));

	for (int i = 0; i < 8; ++i) {
		key[i] = (char)((rand() % 90) + 65);
	}

	key[3] = 'F';
	key[5] = '5';
	key[7] = 'A';
	key[8] = '\0';

	return key;
}

/*
* Makes config file name
*/
char* configName(char* argv){
	char* filename = (char*) calloc(1, 128);
	unsigned int i = 0, j = 0;
	while(argv[i] != '.'){
		filename[i] = argv[i];
		i++;
	}
	return filename;
}

/*
* This function prints the time in the corrent users understandable format
* From 6:8 to 06:08 and so on
*/
void printCorrectTime(unsigned int time[2]){
	if(time[0] < 10){
		printf("0%u:", time[0]);
	}
	else{
		printf("%u:", time[0]);
	}

	if(time[1] < 10){
		printf("0%u\n", time[1]);
	}
	else{
		printf("%u\n", time[1]);
	}
}
