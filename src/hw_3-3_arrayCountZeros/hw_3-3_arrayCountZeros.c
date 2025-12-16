#include <stdio.h>
#define MAX_SIZE 100
int main()
{
    // инициализация массива
    int arr[MAX_SIZE];
    int count = 0;

    int countLen = 0; // счётчик для ввода
    printf("Введите числа для добавления в массив или строку для конца ввода:\n");
    while (scanf("%d", &arr[countLen]) == 1)
        countLen += 1;

    // подсчет нулевых элементов
    for (int i = 0; i < countLen; i++) {
        if (arr[i] == 0) {
            count++;
        }
    }

    // вывод результата
    printf("Массив: ");
    for (int i = 0; i < countLen; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\nКоличество нулевых элементов: %d\n", count);

    return 0;
}
