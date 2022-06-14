#include <stdio.h>
#include <locale.h>
#include <string.h>


#include "functions.h"

int main(int argc, char* argv[])
{
    record* rec;
    FILE* ConfigFile;
    FILE* DB_p;
    int operation = 0;
    int flag = 1;
    char cfgname[64] = { 0, };
    char db[64] = { 0, };
    char key[11] = { 0, };

    int isValidKey = 0;

    ConfigName(argv[0], cfgname);

    if (!(ConfigFile = fopen(cfgname, "r"))) {
        strcpy(db, "database.db");
        genKey(key);
        isValidKey = 1;

        if (!ConfigCreate(cfgname, db, key)) {
            printf("[+] Config file has created succesfully!\n");
        }
        else {
            printf("[!] ERROR: Config file has not created!\n");
        }
    }
    else {
        char content[256] = { 0, };
        char string[256] = { 0, };
        char* kei;

        while (fgets(content, 256, ConfigFile)) {
            noSpaces(content, string);
            kei = ConfigVal(string);

            if (!strcmp(kei, "DB")) {
                getParameter(string, db);
            }
            else if (!strcmp(kei, "KEY")) {
                getParameter(string, key);
            }
        }
        fclose(ConfigFile);
        if (!db) strcpy(db, " database.db");
        isValidKey = checkKey(key);
        printf("[+] Config loaded succesfully!\n");
    }

    if (!(DB_p = fopen(db, "rb"))) {
        rec = NULL;
        printf("WARNING: while loading the database\n");
        if (!DB_Write(&rec, db)) {
            printf("SUCCESS: The database has created!\n");
        }
        else {
            printf("ERROR: while creating the database\n");
        }
    }
    else {
        rec = DB_Read(db);

        if (rec) {
            printf("SUCCESS: The database has loaded successfully!\n");
        }
        else {
            printf("ERROR: while reading the database\n");
        }
        fclose(DB_p);
    }

    if (!isValidKey) {
        printf("[!] Your key is not valid, please check it\n");
    }

    while (flag) {
        printf("[?] Enter operation\n>> ");
        scanf("%d", &operation);

        // menu
        if (operation == 0) {
            printf(" 0: Menu\n");               // +
            printf(" 1: Config info\n");        // +
            printf(" 2: Show DB\n");            // +
            printf(" 3: Create\n");             // +
            printf(" 4: Delete\n");             // +
            printf(" 5: Change\n");             // +
            printf(" 6: [VIP] By provider\n");  // +
            printf(" 7: [VIP] Price below\n");  // +
            printf(" 8: [VIP] Save as\n");      // +
            printf(" 9: [VIP] Export to CSV\n");// +
            printf("10: Options\n\n");          // +
            printf("99: Exit\n");               // +
        }
        // config info
        else if (operation == 1) {
            printf("----[ Config ]----\n");
            printf("DB: %s\n", db);
            printf("KEY: %s\n\n", key);
        }
        // show db
        else if (operation == 2) {
            RecordShow(&rec);
        }
        // create
        else if (operation == 3) {
            rdata t;

            printf("Code [max 8 symbols]: ");
            scanf("%s", t.code);

            printf("Name [64]: ");
            scanf("%s", t.name);

            printf("Group [64]: ");
            scanf("%s", t.group);

            printf("Price [DOUBLE]: ");
            scanf("%lf", &t.price);

            printf("Provider [64]: ");
            scanf("%s", t.provider);

            RecordAdd(&rec, t);

            printf("SUCCESS!\n");
        }
        // delete
        else if (operation == 4) {
            rdata t;
            printf("Enter id: ");
            scanf("%d", &t.id);

            if (RecordFind(&rec, t)) {
                RecordRemove(&rec, t);
                printf("SUCCESS!\n");
            }
            else {
                printf("FAILED! The record hasn't found!\n");
            }
        }
        // change
        else if (operation == 5) {
            rdata t;
            int field = 1;

            printf("Enter id: ");
            scanf("%d", &t.id);

            record* foundRec = RecordFind(&rec, t);

            t.id = foundRec->id;
            strcpy(t.code, foundRec->code);
            strcpy(t.name, foundRec->name);
            strcpy(t.group, foundRec->group);
            strcpy(t.provider, foundRec->provider);
            t.price = foundRec->price;

            if (!(t.id >= 0 && foundRec)) {
                continue;
            }
            printf("1. Code: %s\n", t.code);
            printf("2. Name: %s\n", t.name);
            printf("3. Group: %s\n", t.group);
            printf("4. Price: %lf\n", t.price);
            printf("5. Provider: %s\n\n", t.provider);

            printf("Select a field: ");
            scanf("%d", &field);

            if (!(field >= 1 && field <= 5)) {
                printf("FAILED: Wroung option!\n");
                continue;
            }

            
            char value[64] = { 0, };
            double fvalue = 0;

            printf("Value: ");

            switch (field) {
                case 1:
                case 2:
                case 3:
                case 5:
                    scanf("%s", value);
                    break;
                case 4:
                    scanf("%lf", &fvalue);
                    break;
            }

            switch (field) {
            case 1:
                if (strlen(value) <= 8) {
                    memset(t.code, 0, 8);
                    strcpy(t.code, value);
                }
                else {
                    printf("FAILED: Too long value!\n");
                }
                break;
            case 2:
                if (strlen(value) <= 64) {
                    memset(t.name, 0, 64);
                    strcpy(t.name, value);
                }
                else {
                    printf("FAILED: Too long value!\n");
                }
                break;
            case 3:
                if (strlen(value) <= 64) {
                    memset(t.group, 0, 64);
                    strcpy(t.group, value);
                }
                else {
                    printf("FAILED: Too long value!\n");
                }
                break;
            case 4:
                t.price = fvalue;
                break;
            case 5:
                if (strlen(value) <= 64) {
                    memset(t.provider, 0, 64);
                    strcpy(t.provider, value);
                }
                else {
                    printf("FAILED: Too long value!\n");
                }
                break;
            }
            RecordChange(&foundRec, t);
            printf("SUCCESS!\n");
        }
        // by provider [VIP]
        else if (operation == 6 && isValidKey) {
            if (!isValidKey) {
                printf("[VIP]: This option is avaliable only with license key\n");
                continue;
            }

            char provider[64] = { 0, };
            printf("Enter provider: ");
            scanf("%s", provider);

            RecordsByProvider(&rec, provider);

            printf("SUCCESS!\n");
        }
        // price below [VIP]
        else if (operation == 7 && isValidKey) {
            if (!isValidKey) {
                printf("[VIP]: This option is avaliable only with license key\n");
                continue;
            }
            rdata t;
            memset(t.provider, 0, 64);
            t.price = 0;

            printf("Enter provider: ");
            scanf("%s", t.provider);
            printf("Enter price: ");
            scanf("%lf", &t.price);

            RecordsByGroupBelowPrice(&rec, t);
            printf("SUCCESS!\n");
        }
        // save as [VIP]
        else if (operation == 8 && isValidKey) {
            if (!isValidKey) {
                printf("[VIP]: This option is avaliable only with license key\n");
                continue;
            }

            char newdb[64] = { 0, };

            printf("Enter a new name for database: ");
            scanf("%s", newdb);

            if (newdb[0] == '\n' || newdb[0] == '\0') {
                printf("FAILED! Wrong input!\n");
                continue;
            }

            if (!DB_Write(&rec, newdb)) {
                printf("SUCCESS! Database saved as '%s' succesfully!\n", newdb);
            }
            else {
                printf("ERROR: while saving the database\n");
            }
        }
        // export to csv [VIP]
        else if (operation == 9 && isValidKey) {
            if (!isValidKey) {
                printf("[VIP]: This option is avaliable only with license key\n");
                continue;
            }

            char csvname[64] = { 0, };
            strcpy(csvname, db);
            csvname[strlen(csvname)-2] = 'c';
            csvname[strlen(csvname)-1] = 's';

            strncat(csvname, "v", 1);

            printf("%s\n", csvname);

            if (!DB_ExportCSV(&rec, csvname)) {
                printf("SUCCESS! Database was exported to CSV!\n");
            }
            else {
                printf("ERROR: while exporting to csv!\n");
            }
        }
        // options
        else if (operation == 10) {
            int param = 0;
            char value[64] = { 0, };
            if (!(ConfigFile = fopen(cfgname, "w"))) {
                printf("ERROR: while opening the config file!\n");
                break;
            }
            printf("Select param:\n1. DB\n2. KEY\n>> ");
            scanf("%d", &param);
            
            printf("Enter value:\n>> ");
            scanf("%s", value);

            if (param == 1) {
                memset(db, 0, 64);
                strcpy(db, value);
            }
            else if (param == 2) {
                memset(key, 0, 64);
                strcpy(key, value);
            }
            else {
                printf("[-] Bad param!\n");
                break;
            }

            fprintf(ConfigFile, "; DB = <pathdb>\nDB = %s\n; license key\nKEY = <key>\nKEY = %s", db, key);
            fclose(ConfigFile);
        }
        // exiting
        else if (operation == 99) {
            DB_Write(&rec, db);
            RecordDelete(&rec);
            ConfigCreate(cfgname, db, key);
            printf("[+] Goodbye!\n");
            flag = 0;
        }
        else {
            printf("WARNING: Try again, maybe you have some problems with a licence key\n");
            continue;
        }

    }


    return 0;
}
