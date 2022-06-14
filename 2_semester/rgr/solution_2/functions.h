#ifndef FUNCS_H
#define FUNCS_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

typedef struct rdata {
	int	   id;
	char   code[8];
	char   name[64];
	char   group[64];
	double price;
	char   provider[64];
} rdata;

typedef struct record {
	int	   id;
	char   code[8];
	char   name[64];
	char   group[64];
	double price;
	char   provider[64];
	int	   isRemoved;
	struct record* next;
} record;

/*
* Повертає ім'я конфіг файлу
*
* @param  Шлях до виконаного файлу
* @return ім'я_вик_файлу.cfg
*/
int ConfigName(char* path, char* dest) {
	char* cfgname = strrchr(path, '\\');
	int   length = 0;

	cfgname = (cfgname) ? cfgname + 1 : path;
	length = strlen(cfgname);

	cfgname[length - 3] = 'c';
	cfgname[length - 2] = 'f';
	cfgname[length - 1] = 'g';

	strcpy(dest, cfgname);
	return 0;
}

/*
* Видаляє усі пробіли зі строки
*
* @param string Строка
* @return Строка без пробілів
*/
int noSpaces(const char* string, char* dest) {
	int j = 0;
	char xSpaces[256] = { 0, };

	for (int i = 0; i < strlen(string); ++i) {
		if (!isspace(string[i])) {
			xSpaces[j] = string[i];
			j++;
		}
	}
	xSpaces[j] = '\0';
	strcpy(dest, xSpaces);
	return 0;
}

/*
* Повертає значення параметра від лінії
*
* @param line Значенна параметри після символу "="

*/
char* getParameter(char* line, char* dest) {
	char* value = strchr(line, '=');
	if (value) {
		strcpy(dest, value + 1);
		return value + 1;
	}
	return NULL;
}

/*
* Створює новий конфіг файл та записує у нього значення
*
* @param cfgname  Ім'я конфіг файлу
* @param database БД
* @param key      Ключ
* @return 0 - успіх, 1 - помилка
*/
int ConfigCreate(char* cfgname, char* db, char* key) {
	FILE* cfgfile;
	
	if (!(cfgfile = fopen(cfgname, "w"))) {
		printf("[-] ERROR: while creating config file!\n");
		return 1;
	}

	fprintf(cfgfile, "; DB = <pathdb>\nDB = %s\n; license key\nKEY = <key>\nKEY = %s", db, key);
	fclose(cfgfile);
	return 0;
}

/*
* Генерація ліцензійного ключа
*
* @param dest Змінна для запису ключа
* @return 	  0 - успіх, інакше - помилка
*/
int genKey(char* dest) {
	srand(time(0));
	char key[11] = { 0, };

	key[0] = '5';
	key[1] = '0';

	for (int i = 2; i <= 7; ++i) {
		key[i] = 65 + rand() % 10;
	}

	key[8] = '3';
	key[9] = '1';
	key[10] = '\0';

	strcpy(dest, key);

	return 0;
}

/*
* Перевірка ключа
*
* @param  Ключ
* @return 0 - помилка, 1 - успіх
*/
int checkKey(const char* key) {

	if (!(
		key[0] == '5' && key[1] == '0' && key[8] == '3' && key[9] == '1'
		)) {
		return 0;
	}

	for (int i = 2; i < 8; ++i) {
		if (!(key[i] >= 65 && key[i] <= 65 + 10)) {
			return 0;
		}
	}

	return 1;
}


/*
* Повертає значення параметру
*
* @param  Ключ
* @return 0 - успех, 1 - помилка
*/
char* ConfigVal(char* string) {
	char content[256] = { 0, };
	strcpy(content, string);
	return strtok(content, "=");
}

/*
* Знаходить вузол/запис з необхідними параметрами
* 
* @param rec	Зв'язний список
* @param rdata	Структура, що має в собі всі необхідні параметри за виключенням наступного вузла
* @return		Вказівник на знайдений вузол
*/
record* RecordFind(record** rec, rdata data) {
	if (data.id == -1 && !data.code || !data.group || !data.name) {
		return NULL;
	}
	record* tvar = *rec;
	while (tvar) {
		if (!tvar->isRemoved &&
				((tvar->id == data.id) || 
				(data.code && !strcmp(tvar->code, data.code)) || 
				(data.name && !strcmp(tvar->name, data.name)))
			) {
			return tvar;
		}
		tvar = tvar->next;
	}

	return NULL;
}

/*
* Додає запис у БД (зв'язний список)
* 
* @param rec	Зв'язний список
* @param rdata	Структура, що має в собі всі необхідні параметри за виключенням наступного вузла
*/
void RecordAdd(record** rec, rdata data) {
	data.id = 0;
	record* RecordNew;
	record* tmp = *rec;

	if (*rec == NULL) {
		RecordNew = (record*)malloc(sizeof(record));

		if (!RecordNew) {
			printf("ERROR: In 'RecordAdd' while locating memory\n");
			exit(-1);
		}

		RecordNew->id = 0;
		strncpy(RecordNew->code, data.code, 8);
		strncpy(RecordNew->name, data.name, 64);
		strncpy(RecordNew->group, data.group, 64);
		strncpy(RecordNew->provider, data.provider, 64);
		RecordNew->price = data.price;
		RecordNew->isRemoved = 0;
		RecordNew->next = NULL;

		*rec = RecordNew;
		return;
	}
	tmp = *rec;

	if (tmp->isRemoved) {
		strncpy(tmp->code, data.code, 8);
		strncpy(tmp->name, data.name, 64);
		strncpy(tmp->group, data.group, 64);
		strncpy(tmp->provider, data.provider, 64);
		tmp->price = data.price;
		tmp->isRemoved = 0;
		return;
	}

	while (tmp->next) {
		if (tmp->isRemoved) {
			strncpy(tmp->code, data.code, 8);
			strncpy(tmp->name, data.name, 64);
			strncpy(tmp->group, data.group, 64);
			strncpy(tmp->provider, data.provider, 64);
			tmp->price = data.price;
			tmp->isRemoved = 0;
			return;
		}
		tmp = tmp->next;
		data.id++;
	}

	RecordNew = (record*)malloc(sizeof(record));

	if (!RecordNew) exit(1);

	RecordNew->id = data.id + 1;
	strncpy(RecordNew->code, data.code, 8);
	strncpy(RecordNew->name, data.name, 64);
	strncpy(RecordNew->group, data.group, 64);
	strncpy(RecordNew->provider, data.provider, 64);
	RecordNew->price = data.price;
	RecordNew->isRemoved = 0;
	RecordNew->next = NULL;

	tmp->next = RecordNew;

}

/*
* Змінити дані вузла/записа
* 
* @param rec  Запис
* @param data Дані
*/

void RecordChange(record** rec, rdata data) {
	record* tmp = *rec;

	while (tmp) {
		if (!tmp->isRemoved && (tmp->id == data.id)) {
			strncpy(tmp->code, data.code, 8);
			strncpy(tmp->name, data.name, 64);
			strncpy(tmp->group, data.group, 64);
			strncpy(tmp->provider, data.provider, 64);
			tmp->price = data.price;

			return;
		}
		tmp = tmp->next;
	}
}

/*
* Відмітити запис як видалений
* @param rec Запис
* @param data Дані (використовується лише id)
*/
void RecordRemove(record** rec, rdata data) {
	record* tmp = *rec;
	while (tmp) {
		if (tmp->id == data.id) {
			tmp->isRemoved = 1;
			return;
		}
		tmp = tmp->next;
	}
}

/*
* Виводить усі дані з записів
* 
* @param recПочаткой запис
*/
void RecordShow(record** rec) {
	record* tmp = *rec;

	int count = 0;
	printf("  ID  :  CODE  :  NAME  :  GROUP  :  PRICE  :  PROVIDER  \n");
	while (tmp) {
		if (!tmp->isRemoved) {
			printf("%6d:%8s:%8s:%9s:%9lf:%12s\n", tmp->id, tmp->code, tmp->name, tmp->group, tmp->price, tmp->provider);
			count++;
		}
		tmp = tmp->next;
	}

	if (count == 0) {
		printf("\nNo goods!\n");
	}
	else {
		printf("\nTotal goods: %d\n", count);
	}
}

/*
* Видалити список з пам'яті
* 
* @param rec Запис
*/
void RecordDelete(record** rec) {
	record* tmp = *rec;

	while (tmp) {
		*rec = tmp->next;
		free(tmp);
		tmp = *rec;
	}

}

/*
* Виведення усіх товарів, що постачаються заданим постачальником
* 
* @param rec Запис
* @param provider Постачальник
*/
void RecordsByProvider(record** rec, const char* provider) {
	record* tmp = *rec;

	printf("  ID  :  CODE  :  NAME  :  GROUP  :  PRICE  :  PROVIDER  \n");

	while (tmp) {
		if (!tmp->isRemoved && !strcmp(tmp->provider, provider)) {
			printf("%6d:%8s:%8s:%9s:%9lf:%12s\n", tmp->id, tmp->code, tmp->name, tmp->group, tmp->price, tmp->provider);
		}

		tmp = tmp->next;
	}

}

/*
* Виведення усіх товарів, що постачаються заданим постачальником і ціна нижче за задану
*
* @param rec Запис
* @param provider Постачальник
*/
void RecordsByGroupBelowPrice(record** rec, rdata data) {
	record* tmp = *rec;

	printf("  ID  :  CODE  :  NAME  :  GROUP  :  PRICE  :  PROVIDER  \n");

	while (tmp) {
		if (!tmp->isRemoved && !strcmp(tmp->provider, data.provider) && tmp->price < data.price) {
			printf("%6d:%8s:%8s:%9s:%9lf:%12s\n", tmp->id, tmp->code, tmp->name, tmp->group, tmp->price, tmp->provider);
		}

		tmp = tmp->next;
	}
}

/*
* Запис записів/значень у БД
* 
* @param db Ім'я БД
* @param rec Запис
* @return 0 - успіх, 1 - помилка
*/
int DB_Write(record** rec, const char* db) {
	FILE* fdb;

	if (!(fdb = fopen(db, "wb"))) {
		return 1;
	}
	record* tmp = *rec;
	while (tmp) {

		fwrite(tmp, sizeof(record), 1, fdb);
		tmp = tmp->next;
	}

	fclose(fdb);
	return 0;
}

/*
* Читання записів із файлу
* 
* @param db База даних
* @return Зв'язний список
*/
record* DB_Read(const char* db) {
	FILE* fdb;

	if (!(fdb = fopen(db, "rb"))) {
		return NULL;
	}

	record* tmp = (record*)malloc(sizeof(record));
	record* start = NULL;
	record* end   = NULL;

	if (!tmp) {
		return NULL;
	}

	while (fread(tmp, sizeof(record), 1, fdb)) {

		if (!start) {
			start = (record*)malloc(sizeof(record));
			end = start;

			if (!start) {
				return NULL;
			}
		}
		else {
			end->next = (record*)malloc(sizeof(record));
			end = end->next;

			if (!end) {
				return NULL;
			}
		}
		end->id = tmp->id;
		strncpy(end->code, tmp->code, 8);
		strncpy(end->name, tmp->name, 64);
		strncpy(end->group, tmp->group, 64);
		end->price = tmp->price;
		strncpy(end->provider, tmp->provider, 64);
		end->isRemoved = tmp->isRemoved;
		end->next = NULL;
	}

	fclose(fdb);
	free(tmp);
	return start;
}

/*
* Експортуэ список у csv-файл
* 
* @param db ім'я БД
* @param rec Список записів
* @return 0 - успіх, 1 - помилка
*/
int DB_ExportCSV(record** rec, const char* db) {
	FILE* fdb;

	if (!(fdb = fopen(db, "w"))) {
		return 1;
	}

	record* tmp = *rec;

	while (tmp) {
		if (!tmp->isRemoved) {
			fprintf(fdb, "%d; %s; %s; %s; %g; %s\n", tmp->id, tmp->code, tmp->name, tmp->group, tmp->price, tmp->provider);
		}
		tmp = tmp->next;
	}
	fclose(fdb);
	return 0;

}

#endif
