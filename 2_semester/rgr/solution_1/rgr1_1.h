#ifndef _LIBS_
#define _LIBS_
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#endif

#include "database.h"

/*
* Shows menu
*/
void menu() {
	printf("|-=-=-=[ Menu ]=-=-=-|\n");
	printf("| 0) Menu            |\n");
	printf("| 1) Show config info|\n");
	printf("| 2) Show DB content |\n");
	printf("| 3) Write record    |\n");
	printf("| 4) Remove record   |\n");
	printf("| 5) Change record   |\n");
	printf("| 6) Show by aeroport|\n");
	printf("| 7) After some time |\n");
	printf("| 8) Save DB as...   |\n");
	printf("| 9) Export to CSV   |\n");
	printf("|10) Options         |\n");
	printf("|99) Exit            |\n");
	printf("|-=-=-=-=-=-=-==-=-=-|\n");
}

/*
* Start pending the program
*/
void start_pending() {
	int choice;
	unsigned int intValue = 0;
	char charValue[128] = {0,};
	unsigned int time[2] = {0,};

	struct DbStructure record;

	char newdb[64];
	char* dbptr = &newdb[0];

	menu();
	
	struct ConfigFileStructure config = ConfigFile_getStruct();

	while (1) {
		printf("Enter the operations: ");
		scanf("%d", &choice);
		switch (choice) {
		case 0:
			menu();
			break;
		case 1:
			showConfigInfo();
			break;
		case 2:
			DB_show();
			break;
		case 3:
			printf("[+] You choose 'Write record' operation\n");
			printf("Needed information:\n");
			printf("\t- From Aeroport name\n");
			printf("\t- To Aeroport name\n");
			printf("\t- Flight number\n");
			printf("\t- Time (h:m)\n\n");

			printf("Enter 'From Aeroport name': ");
			scanf("%s", record.fromAeroport);

			printf("Enter 'To Aeroport name': ");
			scanf("%s", record.toAeroport);

			printf("Enter 'Flight number': ");
			scanf("%s", record.flightNumber);

			printf("Enter 'Time (h m)': ");
			scanf("%u%u", &record.time[0], &record.time[1]);

			DB_write(record);
			break;
		case 4:
			printf("[+] Enter the record's id: ");
			scanf("%u", &intValue);
			DB_remove(intValue);
			break;
		case 5:
			printf("[+] Enter the record's id: ");
			scanf("%u", &intValue);
			DB_change(intValue);
			break;
		case 6:
			if(verify_key(config.key)){
				break;
			}
			printf("[+] Enter an aeroport: ");
			scanf("%s", charValue);
			DB_byAero(&charValue[0]);
			break;
		case 7:
			if(verify_key(config.key)){
				break;
			}
			printf("[+] Enter the time (h m): ");
			scanf("%d%d", &time[0], &time[1]);
			DB_afterSomeTime(time);
			break;
		case 8:
			if(verify_key(config.key)){
				break;
			}
			printf("[?] Enter new database name: ");
			scanf("%s", dbptr);
			DB_saveAs(dbptr);
			break;
		case 9:
			if(verify_key(config.key)){
				break;
			}
			DB_exportToCSV();
			break;
		case 10:
			printf("\n[!] WARNING: All your comments will be removed!\n");
			Config_changeOptions();
			break;
		case 99:
			printf("[+] Exiting...\n");
			exit(0);
		case 107:
			strcpy(charValue, generate_key(charValue));
			printf("[+] You entered secret code!\n[+] Generated key: %s\n", charValue);
			break;
		default:
			continue;
		}
		printf("[+] Success!\n");
	}

}

