#ifndef SORTLIST_H
#define SORTLIST_H

// структура узла списка
typedef struct Node {
    int data; // данные узла
    struct Node* next; // указатель на следующий узел
} Node;

// структура списка
typedef struct {
    Node* head; // указатель на начало списка
    int size; // размер списка
} List;

// создание нового пустого списка
List* listCreate();

// вставка элемента в список по заданному индексу
void listInsert(List* list, int index, int value);

// получение элемента по заданному индексу
int listGet(List* list, int index);

// удаление элемента по заданному индексу
void listRemove(List* list, int index);

// распечатывание содержимое списка
void listPrint(List* list);

// удаление всего списка (освобождает память)
void listDelete(List* list);

// находит позицию для вставки в сортированный список
int listPosition(List* list, int value);

// проверяет наличие значения в списке
int listContain(List* list, int value);

// основная функция программы для работы со списком в диалоговом режиме
int main(int argc, char* argv[]);

#endif