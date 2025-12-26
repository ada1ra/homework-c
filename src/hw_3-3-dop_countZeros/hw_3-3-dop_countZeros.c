#include <stdio.h>
#define MAX_SIZE 100
int main()
{
    int count = 0;
    int n;
    printf("Введите числа для добавления в массив или строку для конца ввода:\n");
    while (scanf("%d", &n) == 1) {
    // подсчет нулевых элементов
        if (n == 0)
            count++;
    }

    // вывод результата
    printf("\n\nКоличество нулевых элементов: %d\n", count);

    return 0;
}
