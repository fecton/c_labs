#ifndef _LIBS_
#define _LIBS_
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#endif

#include "funcs.h"

// =====================
// NECCESSARY STRUCTURES
// =====================

struct ConfigFileStructure {
	char path[256];
	char key[256];
};

struct DbStructure {
	char id[32];
	char fromAeroport[128];
	char toAeroport[128];
	char flightNumber[16];
	unsigned int time[2];
};



// ----------------------
// CONFIG FILE FUNCTIONS
// ----------------------

struct ConfigFileStructure ConfigFile_getStruct();

/*
* Printing the information from config
*/
int showConfigInfo() {
	struct ConfigFileStructure config = ConfigFile_getStruct();
	printf("\n-=-=-=-=-= [ Config ] =-=-=-=-=-\n");
	printf("[+] PATH: '%s'\n", config.path);
	printf("[+] KEY : '%s'\n\n", config.key);

	return 0;
}

/*
	* Try to open the config file if it doesn not exist -> create new one with example data
	* @param openType could take two values:
	*	4 - read mode (default)
	*   2 - write mode
	* return Config file pointer
*/
FILE* ConfigFile_open(int openType) {
	FILE* file;

	if (!(file = fopen(config_name, "r+")) || openType == 2) {
		if (openType == 2) {
			file = fopen(config_name, "w");
		}
		else {
			printf("[+] The file '%s' didn't exist than it was created!\n", config_name);
			file = fopen(config_name, "w+");
			char content[] = "; Database file\n; DB = <path>\nDB = mydb.dat\n; Licence key\nKEY = 01AFC567\n";
			fwrite(content, sizeof(content), 1, file);
			fclose(file);
			file = fopen(config_name, "r+");
		}
	}

	return file;
}

/*
	* Try to get params from the config file
	*
	* @param file File pointer
	* @param param Parameter's name in the config name
	* return Paramater value
*/
char* GetParam(char* param) {
	FILE* file = ConfigFile_open(4);

	char* path = (char*)calloc(1, 1024);
	char* varname = (char*)calloc(1, 16);
	char* SPptr = path;
	char* SVptr = varname;
	char tmp;

	int skip = 0;

	while (!feof(file)) {
		if (fscanf(file, "%c", &tmp) == -1) {
			fclose(file);
			return NULL;
		}

		if (skip == 1) {
			if (tmp == '\n') {
				skip = 0;
			}
			path = SPptr;
			continue;
		}
		else
			if (tmp == ';') {
				skip = 1;
				continue;
			}
			else {
				do
				{
					*varname = tmp;
					varname++;
					fscanf(file, "%c", &tmp);
				} while (tmp != ' ' || feof(file));

				while (tmp == '=' || tmp == ' ' || feof(file)) {
					fscanf(file, "%c", &tmp);
				}

				if (tmp != '\n') {
					do
					{
						*path = tmp;
						path++;
						fscanf(file, "%c", &tmp);
					} while (tmp != '\n' || feof(file));
				}
			}
		if (!strcmp(SVptr, param)) {
			fclose(file);
			return SPptr;
		}
		else {
			varname = SVptr;
			path = SPptr;
			memset(SPptr, 0, 1024);
		}
	}
	fclose(file);
}

/*
	* Makes struct variable
	*
	* return struct
*/
struct ConfigFileStructure ConfigFile_getStruct() {
	struct ConfigFileStructure config;

	char arg1[4] = { 0, }, arg2[4] = { 0, };
	strcpy(arg1, "DB");
	strcpy(arg2, "KEY");

	strcpy(config.path, GetParam(&arg1[0]));
	strcpy(config.key, GetParam(&arg2[0]));

	return config;
}

/*
* Prints avaliable options
*/
int Config_showOptions(struct ConfigFileStructure config) {
	printf("[+] Avaliable options:\n");
	printf("\t1) DB  = %s\n", config.path);
	printf("\t2) KEY = %s\n", config.key);
	printf("99) Go back\n");

	return 0;
}

/*
* Update config file information
* @param
*/
int Config_updateFile(struct ConfigFileStructure config) {
	FILE* cfgFile = ConfigFile_open(2);

	fwrite("DB = ", 5, 1, cfgFile);
	fwrite(&config.path[0], ccount(config.path, 2), 1, cfgFile);

	fwrite("\n", 1, 1, cfgFile);

	fwrite("KEY = ", 6, 1, cfgFile);
	fwrite(&config.key[0], ccount(config.key, 2), 1, cfgFile);

	fwrite("\n", 1, 1, cfgFile);

	fclose(cfgFile);

	return 0;
}

/*
* Change the config option
*/
int Config_changeOptions() {
	struct ConfigFileStructure config = ConfigFile_getStruct();
	int option;
	char* tmp = (char*)calloc(1, 128);

	do {
		memset(tmp, 0, sizeof(tmp));
		option = 0;
		Config_showOptions(config);
		printf("[?] Select: ");
		scanf("%d", &option);

		if (option == 1 || option == 2) {
			printf("[?] Value: ");
			scanf("%s", tmp);
		}
		else {
			if (option == 99) {
				break;
			}
			else {
				continue;
			}
		}

		switch (option) {
		case 1:
			memset(config.path, 0, sizeof(config.path));
			strcpy(config.path, tmp);
			break;
		case 2:
			memset(config.key, 0, sizeof(config.key));
			strcpy(config.key, tmp);
			break;
		default:
			printf("[-] Choose a correct operation!\n");
			continue;
		}

		Config_updateFile(config);
	} while (1);

	free(tmp);
	return 0;
}


// ------------------
// DATABASE FUNCTIONS
// ------------------

/*
* Opens the database (config.path) and returnes the pointer on it
* @param config The config structure with path to db
* @param openType Specified type of opening the db (2 - writing, 4 - reading)
*/
FILE* DB_open(struct ConfigFileStructure config, unsigned int openType) {
	FILE* db;
	if (openType == 2) {
		db = fopen(config.path, "wb+");
	}
	else if (!(db = fopen(config.path, "rb+"))) {
		printf("[+] The database '%s' didn't exist than it was created!\n", config.path);
		db = fopen(config.path, "wb+");
	}
	return db;
}


void DB_show() {
	struct ConfigFileStructure config = ConfigFile_getStruct();
	FILE* db = DB_open(config, 4);

	char* record = (char*)calloc(1, 128);
	char* srecord = record;
	char tmp;
	struct DbStructure object;

	char* massive_of_pointers[4] = {
		object.id, object.fromAeroport, object.toAeroport, object.flightNumber
	};

	while (!feof(db)) {
		fscanf(db, "%c", &tmp);
		if (tmp == '\0') {
			printf("[-] Database is empty :(\n");
			return;
		}

		while (tmp != '\n') {
			for (int i = 0; i < 4; ++i) {
				do
				{
					*record = tmp;
					record++;
					fscanf(db, "%c", &tmp);
				} while (tmp != '#' || feof(db));
				fscanf(db, "%c", &tmp);
				strcpy(massive_of_pointers[i], srecord);
				memset(srecord, 0, 128);
				record = srecord;
			}

			for (int i = 0; i < 2; ++i) {
				do
				{
					*record = tmp;
					record++;
					fscanf(db, "%c", &tmp);
				} while ((tmp != '#' && tmp != '\n') || feof(db));
				fscanf(db, "%c", &tmp);
				object.time[i] = (unsigned int)atoi(srecord);
				memset(srecord, 0, 128);
				record = srecord;
			}

			printf("%s  %s  %s  %s  ", object.id, object.fromAeroport, object.toAeroport, object.flightNumber);
			printCorrectTime(object.time);
		}
	}

	fclose(db);
}

/*
* This function checks the correct time format
* If the format is incorrect it'll raise an error
* @param time[2] hours:minutes
*/
int check_time(unsigned int time[2]) {
	if (!((time[1] >= 0 && time[1] < 60) || (time[0] >= 0 && time[0] < 24))) {
		printf("[!] ERROR: wrong time format!\n");
		return 1;
	}
	return 0;
}

/*
* This function write the data to the db
* @param object structure file with all neccessary data
*/
void DB_write(struct DbStructure object) {
	// checking the corret time format
	if (check_time(object.time)) {
		exit(-1);
	}
	struct ConfigFileStructure config = ConfigFile_getStruct();

	// get the last id
	FILE* db = DB_open(config, 4);

	char* record = (char*)calloc(1, 128);
	char* srecord = record;
	char tmp;
	unsigned int last_digest = 0;

	while (!feof(db)) {
		fscanf(db, "%c", &tmp);

		while (tmp != '\n' && tmp != '\0') {
			do
			{
				*record = tmp;
				record++;
				fscanf(db, "%c", &tmp);
			} while (!feof(db) && tmp != '#');

			do {
				fscanf(db, "%c", &tmp);
			} while (!feof(db) && tmp != '\n');

			last_digest = atoi(srecord);

			memset(srecord, 0, 128);
			record = srecord;
		}
	}
	fclose(db);
	last_digest++;
	// finished getting last id

	// opening the database file
	db = DB_open(config, 4);
	// go to the end
	fseek(db, 0, SEEK_END);
	// temp variable
	char maker[32] = { 0, };

	char* massive_of_pointers[3] = {
		object.fromAeroport, object.toAeroport, object.flightNumber
	};

	strcpy(maker, "");
	snprintf(maker, sizeof(maker), "%d", last_digest);
	fwrite(maker, ccount(maker, 1), 1, db);
	fwrite("#", 1, 1, db);

	for (int i = 0; i < 3; ++i) {
		fwrite(massive_of_pointers[i], ccount(massive_of_pointers[i], 1), 1, db);
		fwrite("#", 1, 1, db);
	}

	for (int i = 0; i < 2; ++i) {
		strcpy(maker, "");
		snprintf(maker, sizeof(maker), "%d", object.time[i]);
		fwrite(maker, ccount(maker, 1), 1, db);
		if (i == 0) fwrite("#", 1, 1, db);
	}
	fwrite("\n", 1, 1, db);

	fclose(db);
}

/*
* Exports database to csv format
*/
int DB_exportToCSV() {
	struct ConfigFileStructure config = ConfigFile_getStruct();
	FILE* db = DB_open(config, 4);
	FILE* csv = fopen("export.csv", "wb+");

	char* record = (char*)calloc(1, 128);
	char* srecord = record;
	char tmp;

	while (!feof(db)) {
		fscanf(db, "%c", &tmp);
		while (tmp != '\n') {
			for (int i = 0; i < 6; ++i) {
				do
				{
					*record = tmp;
					record++;
					fscanf(db, "%c", &tmp);
				} while (tmp != '#' && !feof(db) && tmp != '\n');
				fscanf(db, "%c", &tmp);
				fwrite(srecord, ccount(srecord, 1), 1, csv);
				if (i != 5) {
					fwrite(";", 1, 1, csv);
				}
				memset(srecord, 0, 128);
				record = srecord;
			}
			fwrite("\n", 1, 1, csv);
		}
	}

	fclose(db);
	fclose(csv);
	return 0;
}

/*
* This functions created a new database and move the data to it
* @param db_name database name/path
*/
int DB_saveAs(char* db_name) {
	struct ConfigFileStructure config = ConfigFile_getStruct();
	FILE* db = DB_open(config, 4);
	FILE* newdb = fopen(db_name, "wb+");

	char* record = (char*)calloc(1, 128);
	char* srecord = record;
	char tmp;

	while (!feof(db)) {
		fscanf(db, "%c", &tmp);
		while (tmp != '\n') {
			for (int i = 0; i < 6; ++i) {
				do
				{
					*record = tmp;
					record++;
					fscanf(db, "%c", &tmp);
				} while (tmp != '#' && !feof(db) && tmp != '\n');
				fscanf(db, "%c", &tmp);
				fwrite(srecord, ccount(srecord, 1), 1, newdb);
				if (i != 5) {
					fwrite("#", 1, 1, newdb);
				}
				memset(srecord, 0, 128);
				record = srecord;
			}
			fwrite("\n", 1, 1, newdb);
		}
	}

	fclose(db);
	fclose(newdb);
	return 0;
}

/*
* Removed the record with specified id
* @param id record id
*/
void DB_remove(unsigned int id) {
	struct ConfigFileStructure config = ConfigFile_getStruct();
	char* records[4096];

	FILE* db = DB_open(config, 4);

	char* record = (char*)calloc(1, 128);
	char* srecord = record;
	char tmp;
	unsigned int i = 0, mindex = 0;;
	unsigned int current_id = 0;

	while (!feof(db)) {
		fscanf(db, "%c", &tmp);

		if (tmp == '\0') {
			printf("[-] Database is empty :(\n");
			return;
		}

		if (tmp == '\n') {
			break;
		}

		records[i] = (char*)calloc(1, 128);
		do {
			*record = tmp;
			record++;
			fscanf(db, "%c", &tmp);
		} while (tmp != '#');

		current_id = atoi(srecord);

		if (current_id != id) {
			do {
				*record = tmp;
				record++;
				fscanf(db, "%c", &tmp);
			} while (tmp != '\n');

			strcpy(records[mindex], srecord);
			record = srecord;
			memset(record, 0, 128);
			mindex++;
			i++;
		}
		else {
			record = srecord;
			memset(record, 0, 128);
			do {
				fscanf(db, "%c", &tmp);
			} while (tmp != '\n');
			i++;
		}
	}

	fclose(db);
	db = DB_open(config, 2);

	for (int j = 0; j < i - 1; ++j) {
		fwrite(records[j], ccount(records[j], 2), 1, db);
		fwrite("\n", 1, 1, db);
	}
	fclose(db);
}

/*
* Changes the specified by id record info
* @param id record id
*/
void DB_change(unsigned int id) {
	struct ConfigFileStructure config = ConfigFile_getStruct();

	// variables
	char* records[4096];

	FILE* db = DB_open(config, 4);

	char* record = (char*)calloc(1, 128);
	char* srecord = record;
	char tmp;
	unsigned int i = 0, mindex = 0;;
	unsigned int current_id = 0;
	unsigned int choice = 0;
	char maker[64];
	char value[64];
	struct DbStructure object;
	char* massive_of_pointers[4] = {
		object.id, object.fromAeroport, object.toAeroport, object.flightNumber
	};

	// reading the database
	while (!feof(db)) {
		fscanf(db, "%c", &tmp);

		// check for database empty
		if (tmp == '\0') {
			printf("[-] Database is empty :(\n");
			return;
		}

		if (tmp == '\n') {
			break;
		}
		// takes memory for record
		records[i] = (char*)calloc(1, 128);
		do {
			*record = tmp;
			record++;
			fscanf(db, "%c", &tmp);
		} while (tmp != '#');

		current_id = atoi(srecord);

		if (current_id != id) {
			do {
				*record = tmp;
				record++;
				fscanf(db, "%c", &tmp);
			} while (tmp != '\n');

			strcpy(records[mindex], srecord);
			record = srecord;
			memset(record, 0, 128);
			mindex++;
			i++;
		}
		else {
			strcpy(object.id, srecord);
			fscanf(db, "%c", &tmp);

			record = srecord;
			memset(srecord, 0, 128);
			for (int j = 1; j < 4; ++j) {
				do {
					*record = tmp;
					record++;
					fscanf(db, "%c", &tmp);
				} while (tmp != '#');
				fscanf(db, "%c", &tmp);
				memset(massive_of_pointers[j], 0, sizeof(massive_of_pointers[j]));
				strcpy(massive_of_pointers[j], srecord);
				record = srecord;
				memset(srecord, 0, 128);
			}

			for (int j = 0; j < 2; ++j) {
				do {
					*record = tmp;
					record++;
					fscanf(db, "%c", &tmp);
				} while (tmp != '#' && tmp != '\n');
				if (j != 1) {
					fscanf(db, "%c", &tmp);
				}
				object.time[j] = 0;
				object.time[j] = atoi(srecord);
				record = srecord;
				memset(srecord, 0, 128);
			}

			printf(" 1) ID: %s\n", object.id);
			printf(" 2) From Aeroport: %s\n", object.fromAeroport);
			printf(" 3) To Aeroport: %s\n", object.toAeroport);
			printf(" 4) Flight Number: %s\n", object.flightNumber);
			printf(" 5) Time: %d:%d\n", object.time[0], object.time[1]);
			printf("99) Exit...");
			printf("\n[?] Select the argument: ");
			scanf("%d", &choice);

			while (1) {
				if (choice > 0 && choice < 6) {
					if (choice == 5) {
						// enter the values
						printf("[?] Enter time (h m): ");
						scanf("%d%d", &object.time[0], &object.time[1]);
					}
					else
						if (choice == 1) {
							printf("[!] ID cannot be changed!\n");
						}
						else {
							// enter the value
							printf("[?] Enter the value: ");
							scanf("%s", value);
							memset(massive_of_pointers[choice - 1], 0, sizeof(massive_of_pointers[choice - 1]));
							strcpy(massive_of_pointers[choice - 1], &value[0]);
						}

					for (int j = 0; j < 4; ++j) {
						strncat(records[mindex], massive_of_pointers[j], ccount(massive_of_pointers[j], 2));
						strncat(records[mindex], "#", 1);
					}

					for (int j = 0; j < 2; ++j) {
						memset(maker, 0, 64);
						snprintf(maker, 64, "%d", object.time[j]);

						strncat(records[mindex], maker, ccount(maker, 2));
						if (j != 1) {
							strncat(records[mindex], "#", 1);
						}
					}

					break;
				}
				else {
					printf("[-] Wrong option, try again..\n");
				}
			}

			mindex++;
			i++;
		}
	}

	fclose(db);

	// writing a new database
	db = DB_open(config, 2);

	for (int j = 0; j < mindex; ++j) {
		fwrite(records[j], ccount(records[j], 2), 1, db);
		fwrite("\n", 1, 1, db);
	}
	fclose(db);
}

/*
* Gets the records only with specified aeroport
* @param aeroport a specified aeroport
*/
void DB_byAero(char* aeroport) {
	struct ConfigFileStructure config = ConfigFile_getStruct();
	FILE* db = DB_open(config, 4);

	char* record = (char*)calloc(1, 128);
	char* srecord = record;
	char tmp;
	struct DbStructure object;

	char* massive_of_pointers[4] = {
		object.id, object.fromAeroport, object.toAeroport, object.flightNumber
	};

	while (!feof(db)) {
		fscanf(db, "%c", &tmp);
		if (tmp == '\0') {
			printf("[-] Database is empty :(\n");
			return;
		}

		while (tmp != '\n') {
			for (int i = 0; i < 4; ++i) {
				do
				{
					*record = tmp;
					record++;
					fscanf(db, "%c", &tmp);
				} while (tmp != '#' || feof(db));
				fscanf(db, "%c", &tmp);
				strcpy(massive_of_pointers[i], srecord);
				memset(srecord, 0, 128);
				record = srecord;
			}

			for (int i = 0; i < 2; ++i) {
				do
				{
					*record = tmp;
					record++;
					fscanf(db, "%c", &tmp);
				} while ((tmp != '#' && tmp != '\n') || feof(db));
				fscanf(db, "%c", &tmp);
				object.time[i] = (unsigned int)atoi(srecord);
				memset(srecord, 0, 128);
				record = srecord;
			}

			if (!strcmp(object.fromAeroport, aeroport) || !strcmp(object.toAeroport, aeroport)) {
				printf("%s  %s  %s  %s  ", object.id, object.fromAeroport, object.toAeroport, object.flightNumber);
				printCorrectTime(object.time);
			}
		}
	}
	fclose(db);
}

/*
* Gets the records after the specified time
* @param time a massive [hours, minutes]
*/
void DB_afterSomeTime(unsigned int time[2]) {
	struct ConfigFileStructure config = ConfigFile_getStruct();
	FILE* db = DB_open(config, 4);

	char* record = (char*)calloc(1, 128);
	char* srecord = record;
	char tmp;
	struct DbStructure object;

	char* massive_of_pointers[4] = {
		object.id, object.fromAeroport, object.toAeroport, object.flightNumber
	};

	while (!feof(db)) {
		fscanf(db, "%c", &tmp);
		if (tmp == '\0') {
			printf("[-] Database is empty :(\n");
			return;
		}

		while (tmp != '\n') {
			for (int i = 0; i < 4; ++i) {
				do
				{
					*record = tmp;
					record++;
					fscanf(db, "%c", &tmp);
				} while (tmp != '#' || feof(db));
				fscanf(db, "%c", &tmp);
				strcpy(massive_of_pointers[i], srecord);
				memset(srecord, 0, 128);
				record = srecord;
			}

			for (int i = 0; i < 2; ++i) {
				do
				{
					*record = tmp;
					record++;
					fscanf(db, "%c", &tmp);
				} while ((tmp != '#' && tmp != '\n') || feof(db));
				fscanf(db, "%c", &tmp);
				object.time[i] = (unsigned int)atoi(srecord);
				memset(srecord, 0, 128);
				record = srecord;
			}

			if ((time[0] < object.time[0]) || (time[0] == object.time[0] && time[1] <= object.time[1])) {
				printf("%s  %s  %s  %s  ", object.id, object.fromAeroport, object.toAeroport, object.flightNumber);
				printCorrectTime(object.time);
			}
		}
	}
	fclose(db);
}
