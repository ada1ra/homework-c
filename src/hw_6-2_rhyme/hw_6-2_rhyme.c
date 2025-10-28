#include "hw_6-2_rhyme.h"
#include <stdio.h>
#include <stdlib.h>

// структура узла циклического списка
typedef struct Node {
    int number;
    struct Node* next;
} Node;

// функция создания нового узла
Node* createNode(int value)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Ошибка выделения памяти\n");
        return NULL;
    }
    newNode->number = value;
    newNode->next = NULL;
    return newNode;
}

// функция создания циклического списка из n воинов
Node* createCircularList(int n)
{
    if (n <= 0) {
        return NULL;
    }

    Node* head = createNode(1);
    if (head == NULL) {
        return NULL;
    }

    Node* current = head;
    for (int i = 2; i <= n; i++) {
        Node* newNode = createNode(i);
        if (newNode == NULL) {
            // освобождаем уже созданные узлы при ошибке
            Node* temp = head;
            while (temp != NULL) {
                Node* toDelete = temp;
                temp = temp->next;
                free(toDelete);
            }
            return NULL;
        }
        current->next = newNode;
        current = newNode;
    }
    current->next = head; // замыкаем список
    return head;
}

// функция решения задачи Иосифа Флавия
int josephusProblem(int n, int m)
{
    if (n <= 0 || m <= 0) {
        return -1; // некорректные входные данные
    }

    if (n == 1) {
        return 1; // если воин всего один, он и останется
    }

    // создаем циклический список
    Node* current = createCircularList(n);
    if (current == NULL) {
        return -1;
    }

    // находим узел, предшествующий current (последний узел)
    Node* previous = current;
    while (previous->next != current) {
        previous = previous->next;
    }

    // пока в списке больше одного узла
    while (current->next != current) {
        // отсчитываем m-1 шагов
        for (int i = 1; i < m; i++) {
            previous = current;
            current = current->next;
        }

        // удаляем текущий узел
        Node* toDelete = current;
        previous->next = current->next;
        current = current->next;
        free(toDelete);
    }

    // сохраняем результат и освобождаем последний узел
    int result = current->number;
    free(current);
    return result;
}

int main()
{
    int n, m;

    printf("Введите количество воинов (n): ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Некорректный ввод n\n");
        return 1;
    }

    printf("Введите шаг (m): ");
    if (scanf("%d", &m) != 1 || m <= 0) {
        printf("Некорректный ввод m\n");
        return 1;
    }

    int k = josephusProblem(n, m);
    if (k != -1) {
        printf("Последний оставшийся воин имеет номер: %d\n", k);
    } else {
        printf("Произошла ошибка при вычислении\n");
    }

    return 0;
}