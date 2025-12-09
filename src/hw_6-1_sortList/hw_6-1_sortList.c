#include "hw_6-1_sortList.h"
#include <stdio.h>
#include <stdlib.h>

// создание нового пустого списка
List* listCreate()
{
    List* list = (List*)malloc(sizeof(List));
    if (list == NULL) {
        printf("Ошибка выделения памяти для списка\n");
        exit(1);
    }
    list->head = NULL;
    list->size = 0;
    return list;
}

// вставка элемента в список по заданному индексу
void listInsert(List* list, int index, int value)
{
    // проверка корректности индекса
    if (index < 0 || index > list->size) {
        printf("Некорректный индекс для вставки\n");
        return;
    }

    // создаем новый узел
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Ошибка выделения памяти для узла\n");
        return;
    }
    newNode->data = value;

    // вставка в начало списка
    if (index == 0) {
        newNode->next = list->head;
        list->head = newNode;
    } else {
        // поиск позиции для вставки
        Node* current = list->head;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        // вставка между узлами
        newNode->next = current->next;
        current->next = newNode;
    }
    list->size++;
}

// получение элемента по заданному индексу
int listGet(List* list, int index)
{
    // проверка корректности индекса
    if (index < 0 || index >= list->size) {
        printf("Некорректный индекс для получения элемента\n");
        return -1;
    }

    // поиск нужного узла
    Node* current = list->head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    return current->data;
}

// удаление элемента по заданному индексу
void listRemove(List* list, int index)
{
    // проверка корректности индекса
    if (index < 0 || index >= list->size) {
        printf("Некорректный индекс для удаления\n");
        return;
    }

    Node* toDelete;
    // удаление из начала списка
    if (index == 0) {
        toDelete = list->head;
        list->head = list->head->next;
    } else {
        // поиск узла перед удаляемым
        Node* current = list->head;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        toDelete = current->next;
        current->next = toDelete->next;
    }
    // освобождение памяти
    free(toDelete);
    list->size--;
}

// распечатывание содержимое списка
void listPrint(List* list)
{
    if (list->size == 0) {
        printf("Список пуст\n");
        return;
    }

    Node* current = list->head;
    printf("Содержимое списка: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// удаление всего списка (освобождает память)
void listDelete(List* list)
{
    Node* current = list->head;
    // последовательное удаление всех узлов
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    // освобождение структуры списка
    free(list);
}

// находит позицию для вставки в сортированный список
int listPosition(List* list, int value)
{
    if (list->size == 0)
        return 0;

    Node* current = list->head;
    int position = 0;

    // ищем первую позицию, где следующий элемент больше вставляемого значения
    while (current != NULL && current->data < value) {
        current = current->next;
        position++;
    }
    return position;
}

// проверяет наличие значения в списке
int listContain(List* list, int value)
{
    Node* current = list->head;
    int position = 0;

    while (current != NULL) {
        if (current->data == value) {
            return position;
        }
        current = current->next;
        position++;
    }
    return -1;
}
