#include <stdio.h>
#include "hw_6-1_sortList.h"

// основная функция программы
int main()
{
    List* list = listCreate();
    int command;
    int value;

    printf("Программа для работы с сортированным списком\n");

    do {
        // вывод меню
        printf("\nМеню операций:\n");
        printf("0 - выйти\n");
        printf("1 - добавить значение в сортированный список\n");
        printf("2 - удалить значение из списка\n");
        printf("3 - распечатать список\n");
        printf("Выберите операцию: ");

        scanf("%d", &command);

        switch (command) {
        case 0:
            // выход из программы
            printf("Завершение работы программы\n");
            break;

        case 1:
            // добавление значения в сортированный список
            printf("Введите значение для добавления: ");
            if (scanf("%d", &value) != 1) {
                printf("Ошибка, введите целое число");
                // очистка буфера при ошибке
                int temp;
                while ((temp = getchar()) != '\n' && temp != EOF);
                break;
                }
            // находим позицию для сохранения сортировки
            int position = listPosition(list, value);
            listInsert(list, position, value);

            printf("Значение %d добавлено в позицию %d\n", value, position);
            break;

        case 2:
            // удаление значения из списка
            printf("Введите значение для удаления: ");
            scanf("%d", &value);

            // проверяем наличие значения в списке
            int removePosition = listContain(list, value);
            if (removePosition != -1) {
                listRemove(list, removePosition);
                printf("Значение %d удалено из списка\n", value);
            } else {
                printf("Значение %d не найдено в списке\n", value);
            }
            break;

        case 3:
            // печать списка
            listPrint(list);
            break;

        default:
            printf("Неизвестная команда, попробуйте снова\n");
            break;
        }

    } while (command != 0);

    // освобождение памяти перед выходом
    listDelete(list);

    return 0;
}
