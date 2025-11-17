#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hw_10_testingSortList.h"

// ВСПОМОГАТЕЛЬНЫЕ ФУНКЦИИ ДЛЯ ТЕСТИРОВАНИЯ

// сравнение списка с массивом
int compareListWithArray(List* list, int expected[], int size) {
    // проверяем размер списка
    if (list->size != size) {
        return 0; // размеры не совпадают
    }
    
    // проверяем каждый элемент
    Node* current = list->head;
    for (int i = 0; i < size; i++) {
        if (current == NULL || current->data != expected[i]) {
            return 0; // элементы не совпадают
        }
        current = current->next;
    }
    
    return 1; 
}

// печать списка в виде массива
void printListAsArray(List* list) {
    printf("[");
    Node* current = list->head;
    while (current != NULL) {
        printf("%d", current->data);
        if (current->next != NULL) {
            printf(", ");
        }
        current = current->next;
    }
    printf("]");
}

// ТЕСТОВЫЕ ФУНКЦИИ

// тест создания пустого списка
int testCreateEmptyList() {
    printf("Тест 1: Создание пустого списка... ");
    
    List* list = listCreate();
    
    if (list == NULL) {
        printf("FAIL: Не удалось создать список\n");
        return 0;
    }
    
    if (list->head != NULL) {
        printf("FAIL: Голова списка должна быть NULL\n");
        listDelete(list);
        return 0;
    }
    
    if (list->size != 0) {
        printf("FAIL: Размер пустого списка должен быть 0\n");
        listDelete(list);
        return 0;
    }
    
    listDelete(list);
    printf("PASS\n");
    return 1;
}

// тест добавления одного элемента
int testAddSingleElement() {
    printf("Тест 2: Добавление одного элемента... ");
    
    List* list = listCreate();
    
    // добавляем элемент
    int position = listPosition(list, 5);
    listInsert(list, position, 5);
    
    // проверяем результат
    if (list->size != 1) {
        printf("FAIL: Размер должен быть 1\n");
        listDelete(list);
        return 0;
    }
    
    if (list->head == NULL || list->head->data != 5) {
        printf("FAIL: Неверные данные в голове списка\n");
        listDelete(list);
        return 0;
    }
    
    int expected[] = {5};
    if (!compareListWithArray(list, expected, 1)) {
        printf("FAIL: Список содержит неверные данные\n");
        listDelete(list);
        return 0;
    }
    
    listDelete(list);
    printf("PASS\n");
    return 1;
}

// тест добавления нескольких элементов в правильном порядке
int testAddMultipleElementsSorted() {
    printf("Тест 3: Добавление нескольких элементов в сортированном порядке... ");
    
    List* list = listCreate();

    listInsert(list, listPosition(list, 3), 3);
    listInsert(list, listPosition(list, 1), 1);
    listInsert(list, listPosition(list, 2), 2);
    listInsert(list, listPosition(list, 5), 5);
    listInsert(list, listPosition(list, 4), 4);

    int expected[] = {1, 2, 3, 4, 5};
    if (!compareListWithArray(list, expected, 5)) {
        printf("FAIL: Список не отсортирован правильно. Получено: ");
        printListAsArray(list);
        printf(", ожидалось: [1, 2, 3, 4, 5]\n");
        listDelete(list);
        return 0;
    }
    
    listDelete(list);
    printf("PASS\n");
    return 1;
}

// тест добавления дубликатов
int testAddDuplicates() {
    printf("Тест 4: Добавление дубликатов... ");
    
    List* list = listCreate();
    
    listInsert(list, listPosition(list, 2), 2);
    listInsert(list, listPosition(list, 2), 2);
    listInsert(list, listPosition(list, 2), 2);

    int expected[] = {2, 2, 2};
    if (!compareListWithArray(list, expected, 3)) {
        printf("FAIL: Дубликаты обработаны неправильно. Получено: ");
        printListAsArray(list);
        printf(", ожидалось: [2, 2, 2]\n");
        listDelete(list);
        return 0;
    }
    
    listDelete(list);
    printf("PASS\n");
    return 1;
}

// тест удаления существующего элемента
int testRemoveExistingElement() {
    printf("Тест 5: Удаление существующего элемента... ");
    
    List* list = listCreate();
    
    for (int i = 1; i <= 5; i++) {
        listInsert(list, listPosition(list, i), i);
    }
    
    int removePos = listContain(list, 3);
    if (removePos == -1) {
        printf("FAIL: Элемент 3 не найден в списке\n");
        listDelete(list);
        return 0;
    }
    
    listRemove(list, removePos);

    int expected[] = {1, 2, 4, 5};
    if (!compareListWithArray(list, expected, 4)) {
        printf("FAIL: После удаления список содержит неверные данные. Получено: ");
        printListAsArray(list);
        printf(", ожидалось: [1, 2, 4, 5]\n");
        listDelete(list);
        return 0;
    }
    
    listDelete(list);
    printf("PASS\n");
    return 1;
}

// тест удаления несуществующего элемента
int testRemoveNonExistingElement() {
    printf("Тест 6: Удаление несуществующего элемента... ");
    
    List* list = listCreate();

    for (int i = 1; i <= 3; i++) {
        listInsert(list, listPosition(list, i), i);
    }

    int originalSize = list->size;
    int removePos = listContain(list, 999); // Элемента нет в списке
    
    if (removePos != -1) {
        printf("FAIL: Несуществующий элемент не должен быть найден\n");
        listDelete(list);
        return 0;
    }

    if (list->size != originalSize) {
        printf("FAIL: Размер списка изменился при удалении несуществующего элемента\n");
        listDelete(list);
        return 0;
    }
    
    listDelete(list);
    printf("PASS\n");
    return 1;
}

// тест удаления из пустого списка
int testRemoveFromEmptyList() {
    printf("Тест 7: Удаление из пустого списка... ");
    
    List* list = listCreate();
    
    int originalSize = list->size;
    listRemove(list, 0);
    
    if (list->size != 0) {
        printf("FAIL: Размер пустого списка изменился после удаления\n");
        listDelete(list);
        return 0;
    }
    
    listDelete(list);
    printf("PASS\n");
    return 1;
}

// тест поиска позиции в пустом списке
int testPositionInEmptyList() {
    printf("Тест 8: Поиск позиции в пустом списке... ");
    
    List* list = listCreate();
    
    int pos = listPosition(list, 5);
    
    if (pos != 0) {
        printf("FAIL: Позиция в пустом списке должна быть 0, получено %d\n", pos);
        listDelete(list);
        return 0;
    }
    
    listDelete(list);
    printf("PASS\n");
    return 1;
}

// тест поиска позиции для вставки в начало
int testPositionAtBeginning() {
    printf("Тест 9: Поиск позиции для вставки в начало... ");
    
    List* list = listCreate();
    
    for (int i = 2; i <= 4; i++) {
        listInsert(list, listPosition(list, i), i);
    }
    
    int pos = listPosition(list, 1);
    
    if (pos != 0) {
        printf("FAIL: Позиция для 1 должна быть 0, получено %d\n", pos);
        listDelete(list);
        return 0;
    }
    
    listDelete(list);
    printf("PASS\n");
    return 1;
}

// тест поиска позиции для вставки в конец
int testPositionAtEnd() {
    printf("Тест 10: Поиск позиции для вставки в конец... ");
    
    List* list = listCreate();

    for (int i = 1; i <= 3; i++) {
        listInsert(list, listPosition(list, i), i);
    }

    int pos = listPosition(list, 5);
    
    if (pos != 3) {
        printf("FAIL: Позиция для 5 должна быть 3, получено %d\n", pos);
        listDelete(list);
        return 0;
    }
    
    listDelete(list);
    printf("PASS\n");
    return 1;
}

// ГЛАВНАЯ ФУНКЦИЯ ТЕСТИРОВАНИЯ

void runTests() {
    printf("Запуск тестов для сортированного списка\n");
    
    int totalTests = 0;
    int passedTests = 0;
    
    // Запускаем все тесты и подсчитываем результаты
    if (testCreateEmptyList()) passedTests++; totalTests++;
    if (testAddSingleElement()) passedTests++; totalTests++;
    if (testAddMultipleElementsSorted()) passedTests++; totalTests++;
    if (testAddDuplicates()) passedTests++; totalTests++;
    if (testRemoveExistingElement()) passedTests++; totalTests++;
    if (testRemoveNonExistingElement()) passedTests++; totalTests++;
    if (testRemoveFromEmptyList()) passedTests++; totalTests++;
    if (testPositionInEmptyList()) passedTests++; totalTests++;
    if (testPositionAtBeginning()) passedTests++; totalTests++;
    if (testPositionAtEnd()) passedTests++; totalTests++;
    
    printf("Результаты тестирования:\n");
    printf("Всего тестов: %d\n", totalTests);
    printf("Пройдено: %d\n", passedTests);
    printf("Не пройдено: %d\n", totalTests - passedTests);
}

// ОСНОВНАЯ ФУНКЦИЯ ПРОГРАММЫ

int main(int argc, char* argv[]) {
    // проверяем аргументы командной строки
    if (argc == 2 && strcmp(argv[1], "--test") == 0) {
        // запускаем тесты
        runTests();
        return 0;
    }
    
    // основная функция работы в диалоговом режиме
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