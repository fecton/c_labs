#include "pch.h"
#include "database.h"

/*
1#Paris#Donetsk#13#13#0
2#Lugansk#New-York#53#18#20
3#Egypt#Lugansk#53#6#14
4#Russia#Hell#43#6#6
*/

TEST(rgr, showConfigInfo_test) {
  EXPECT_EQ(0, showConfigInfo());
}

TEST(rgr, getParam_test) {
	EXPECT_STRCASEEQ(GetParam("KEY"), "01AFC567");
	EXPECT_STRCASEEQ(GetParam("DB"), "mydb.dat");
}

TEST(rgr, getConfigStruct_test) {
	struct ConfigFileStructure config = ConfigFile_getStruct();
	EXPECT_STRCASEEQ(config.key, "01AFC567");
	EXPECT_STRCASEEQ(config.path, "mydb.dat");
}

TEST(rgr, showOptions_test) {
	struct ConfigFileStructure config = ConfigFile_getStruct();
	EXPECT_EQ(0, Config_showOptions(config));
}

TEST(rgr, ccount_test) {
	EXPECT_EQ(7l, ccount("Hello, world", 1));
	EXPECT_EQ(12, ccount("Hello, world", 2));
}

TEST(rgr, compareContent_test) {
	char* db_content = (char*)calloc(1, 4096);
	char* pattern = (char*)calloc(1, 4096);
	strcpy(pattern, "1#Paris#Donetsk#13#13#0\n2#Lugansk#New-York#53#18#20\n3#Egypt#Lugansk#53#6#14\n4#Russia#Hell#43#6#6\n");
	char* spointer = db_content;
	struct ConfigFileStructure config = ConfigFile_getStruct();
	FILE* file = DB_open(config, 4);
	while (!feof(file)) {
		fscanf(file, "%c", db_content);
		db_content++;
	}
	fclose(file);
	EXPECT_STRCASEEQ(pattern, spointer);
}

TEST(rgr, checkTime_test) {
	unsigned int
		test1[2] = { 15, 0 },
		test2[2] = { 242, 632 },
		test3[2] = { 0,0 },
		test4[2] = { -23, -53 };

	EXPECT_EQ(0, check_time(test1));
	EXPECT_EQ(1, check_time(test2));
	EXPECT_EQ(0, check_time(test3));
	EXPECT_EQ(1, check_time(test4));
}

TEST(rgr, generateKey_test) {
	char key[9];

	strcpy(key, generate_key());
	printf("[!!!] KEY: %s\n", key);

	EXPECT_EQ(0, verify_key(key));
}

TEST(rgr, verifyKey_test) {
	char* key1 = (char*)calloc(1, 64);
	char* key2 = (char*)calloc(1, 64);

	strcpy(key1, "01AFC567");
	strcpy(key2, "FAKEKEY");

	EXPECT_EQ(0, verify_key(key1));
	EXPECT_EQ(1, verify_key(key2));
}

TEST(rgr, dbWrite_test) {
	struct DbStructure object;
	strcpy(object.fromAeroport, "Pekin");
	strcpy(object.toAeroport, "Warshava");
	strcpy(object.flightNumber, "11");
	object.time[0] = 6;
	object.time[1] = 10;

	DB_write(object);

	char* db_content = (char*)calloc(1, 4096);
	char* pattern = (char*)calloc(1, 4096);
	strcpy(pattern, "1#Paris#Donetsk#13#13#0\n2#Lugansk#New-York#53#18#20\n3#Egypt#Lugansk#53#6#14\n4#Russia#Hell#43#6#6\n5#Pekin#Warshava#11#6#10\n");
	char* spointer = db_content;
	struct ConfigFileStructure config = ConfigFile_getStruct();
	FILE* file = DB_open(config, 4);
	while (!feof(file)) {
		fscanf(file, "%c", db_content);
		db_content++;
	}
	fclose(file);
	EXPECT_STRCASEEQ(pattern, spointer);
}

TEST(rgr, dbRemove_test) {
	DB_remove(4);

	char* db_content = (char*)calloc(1, 4096);
	char* pattern = (char*)calloc(1, 4096);
	strcpy(pattern, "1#Paris#Donetsk#13#13#0\n2#Lugansk#New-York#53#18#20\n3#Egypt#Lugansk#53#6#14\n5#Pekin#Warshava#11#6#10\n");
	char* spointer = db_content;
	struct ConfigFileStructure config = ConfigFile_getStruct();
	FILE* file = DB_open(config, 4);
	while (!feof(file)) {
		fscanf(file, "%c", db_content);
		db_content++;
	}
	fclose(file);
	EXPECT_STRCASEEQ(pattern, spointer);
}

TEST(rgr, restoreDB) {
	struct ConfigFileStructure config = ConfigFile_getStruct();
	FILE* db = DB_open(config, 2);
	char* content = (char*)calloc(1, 4096);

	strcpy(content, "1#Paris#Donetsk#13#13#0\n2#Lugansk#New-York#53#18#20\n3#Egypt#Lugansk#53#6#14\n4#Russia#Hell#43#6#6\n");

	fwrite(content, ccount(content, 2), 1, db);

	fclose(db);
	EXPECT_TRUE(1);
}
