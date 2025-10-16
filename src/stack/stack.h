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
int stack_push(Stack* stack, int value);   // положить элемент на стек
int stack_pop(Stack* stack);               // взять элемент со стека
int stack_peek(Stack* stack);              // посмотреть на элемент на вершине стека

// служебные функции
Stack* stack_new(void);                    // создать пустой стек
void stack_delete(Stack* stack);           // удалить весь стек (освободить память)

#endif