#include "kr_2_1_palindrom.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// структура узла списка
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// функция для создания нового узла
Node* createNode(int value)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// функция для добавления элемента
Node* append(Node* head, int value)
{
    Node* newNode = createNode(value);

    if (head == NULL)
        return newNode;

    Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;

    return head;
}

// функция разворота списка
Node* reverseList(Node* head)
{
    Node* newHead = NULL;
    Node* current = head;
    Node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = newHead;
        newHead = current;
        current = next;
    }

    return newHead;
}

// функция для сравнения двух списков
bool compareLists(Node* list1, Node* list2)
{
    Node* curr1 = list1;
    Node* curr2 = list2;
    while (curr1 != NULL && curr2 != NULL) {
        if (curr1->data != curr2->data) {
            return false;
        }
        curr1 = curr1->next;
        curr2 = curr2->next;
    }
    return (curr1 == NULL && curr2 == NULL);
}

// функция для создания копии списка
Node* copyList(Node* head)
{
    if (head == NULL)
        return NULL;
    Node* newHead = createNode(head->data);
    Node* currentOrig = head->next;
    Node* currentCopy = newHead;

    while (currentOrig != NULL) {
        currentCopy->next = createNode(currentOrig->data);
        currentCopy = currentCopy->next;
        currentOrig = currentOrig->next;
    }
    return newHead;
}

// функция для проверки симметричности списка
bool isSymmetric(Node* head)
{
    if (head == NULL || head->next == NULL)
        return true;

    Node* copy = copyList(head);
    copy = reverseList(copy);
    bool result = compareLists(head, copy);
    Node* temp = copy;
    while (temp != NULL) {
        Node* next = temp->next;
        free(temp);
        temp = next;
    }
    return result;
}

// функция для освобождения памяти
void freeList(Node* head)
{
    Node* current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
}

// функция создания списка из массива для тестов
Node* createListFromArray(int arr[], int n)
{
    Node* head = NULL;
    for (int i = 0; i < n; i++) {
        head = append(head, arr[i]);
    }
    return head;
}

// тест с несимметричным списком
void test1()
{
    int arr[] = { 10, 20, 30, 40, 20, 10 };
    Node* list = createListFromArray(arr, 6);
    printf("Ожидается: не симметричный\n");
    printf("Результат: %s\n\n", isSymmetric(list) ? "симметричный ✗" : "не симметричный ✓");

    freeList(list);
}

// тест со списком из одного элемента
void test2()
{
    int arr[] = { 42 };
    Node* list = createListFromArray(arr, 1);
    printf("Ожидается: симметричный\n");
    printf("Результат: %s\n\n", isSymmetric(list) ? "симметричный ✓" : "не симметричный ✗");

    freeList(list);
}

// тест с пустым списком
void test3()
{
    Node* list = NULL;
    printf("Ожидается: симметричный\n");
    printf("Результат: %s\n\n", isSymmetric(list) ? "симметричный ✓" : "не симметричный ✗");

    freeList(list);
}

int main()
{
    Node* head = NULL;
    int number;

    printf("Введите натуральные числа (0 для окончания ввода): \n");

    while (scanf("%d", &number) == 1 && number > 0) {
        head = append(head, number);
    }

    // проверяем симметричность
    if (isSymmetric(head)) {
        printf("Список симметричен.\n");
    } else {
        printf("Список не симметричен.\n");
    }

    // освобождаем память
    freeList(head);

    return 0;
}
