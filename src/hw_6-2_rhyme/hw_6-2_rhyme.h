#ifndef RHYME_H
#define RHYME_H

// структура узла циклического списка
typedef struct Node {
    int number;
    struct Node* next;
} Node;

// функция создания нового узла
Node* createNode(int value);

// функция создания циклического списка из n воинов
Node* createCircularList(int n);

// функция решения задачи Иосифа Флавия
int josephusProblem(int n, int m);

// основная функция, принимающая данные и выводящая результат
int main();

#endif