#ifndef PALINDROM_H
#define PALINDROM_H

// структура узла списка
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// функция для создания нового узла
Node* createNode(int value);

// функция для добавления элемента
Node* append(Node* head, int value);

// функция разворота списка
Node* reverseList(Node* head);

// функция для сравнения двух списков
bool compareLists(Node* list1, Node* list2);

// функция для проверки симметричности списка
bool isSymmetric(Node* head);

// функция для освобождения памяти
void freeList(Node* head);

// функция создания списка из массива для тестов
Node* createListFromArray(int arr[], int n);

// тест с несимметричным списком
void test1();

// тест со списком из одного элемента
void test2();

// тест с пустым списком
void test3();

#endif
