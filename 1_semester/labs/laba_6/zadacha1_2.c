#include <stdio.h>
#include <locale.h>

int main(int argc, char const *argv[])
{
    setlocale(LC_CTYPE, "rus");
    char choice;

    printf("Введите число (1-7): ");
    scanf("%hd", &choice);

    switch (choice)
    {
    case 1:
        printf("Понеділок");
        break;
    case 2:
        printf("Вівторок");
        break;
    case 3:
        printf("Середа");
        break;
    case 4:
        printf("Четверг");
        break;
    case 5:
        printf("П'ятница");
        break;
    case 6:
        printf("Субота");
        break;
    case 7:
        printf("Неділя");
        break;
                            
    default:
        printf("Неправильне число");
        break;
    }

    return 0;
}
