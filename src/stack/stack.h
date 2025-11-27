#ifndef STACK_H
#define STACK_H

#include <stddef.h>

// максимальный размер стека
#define STACK_MAX_SIZE 100

// структура узла стека
typedef struct Node {
    int data;                              // целочисленные данные
    struct Node* next;                     // указатель на следующий узел
} Node;

// структура стека
typedef struct {
    Node* top;                             // указатель на вершину стека
} Stack;

// основные операции
int stackPush(Stack* stack, int value);   // положить элемент на стек
int stackPop(Stack* stack);               // взять элемент со стека
int stackPeek(Stack* stack);              // посмотреть на элемент на вершине стека

// служебные функции
Stack* stackNew(void);                    // создать пустой стек
void stackDelete(Stack* stack);           // удалить весь стек (освободить память)

#endif