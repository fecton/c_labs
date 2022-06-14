#ifndef _LIBS_
#define _LIBS_
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#endif

char config_name[128];
#include "rgr1_1.h"

int main(int argc, char* argv[]) {
	printf("-=-= [ Welcome to Fecton's database! ] =-=-\n\n");

	memset(config_name, 0, 128);
	strcpy(config_name, configName(argv[0]));
	strncat(config_name, ".cfg", 4);

	start_pending();

	return 0;
}
