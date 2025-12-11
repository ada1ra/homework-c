#include <stdio.h>
#include <string.h>

/* Вычисление количества вхождений подстроки в строку */
int subStringCount(char* mainString, char* subString)
{
    char* temp = mainString;
    int count = 0;

    char* mainStringEnd = mainString + strlen(mainString); // вычисляем указатель на конец строки
    while (temp != NULL && temp < mainStringEnd) {
        char* result = strstr(temp, subString); // поиск указателя на первый элемент найденной подстроки
        if (result && temp) {
            count++;
            temp = result + strlen(subString); // перемещаемся за найденную подстроку
        } else
            break;
    }
    return count;
}

int main()
{
    char* mainString;
    printf("Введите строку, в которой будет производится поиск:\n");
    scanf("%s", mainString);

    char* subString;
    printf("Введите строку для поиска:\n");
    scanf("%s", subString);

    int result = subStringCount(mainString, subString);
    printf("\nРезультат — %d\n", result);
    return 0;
}
