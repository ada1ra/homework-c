#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

// создание пустого стека
Stack* stackNew(void) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    if (stack != NULL) {
        stack->top = NULL;
    }
    return stack;
}

// добавление элемента на стек
int stackPush(Stack* stack, int value) {
    if (stack == NULL) {
        printf("Stack is NULL!\n");
        return -1;
    }
    
    // создаем новый узел
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Memory failed!\n");
        return -1;
    }
    
    // заполняем узел
    new_node->data = value;
    new_node->next = stack->top;
    
    // обновляем вершину стека
    stack->top = new_node;
}

// взятие элемента со стека
int stackPop(Stack* stack) {
    if (stack == NULL || stack->top == NULL) {
        printf("Stack is empty!\n");
        return -1;
    }
    
    // сохраняем данные из вершины
    Node* temp = stack->top;
    int value = temp->data;
    
    // перемещаем вершину на следующий элемент
    stack->top = stack->top->next;
    
    // освобождаем память удаляемого узла
    free(temp);
    
    return value;
}

// просмотр элемента на вершине стека
int stackPeek(Stack* stack) {
    if (stack == NULL || stack->top == NULL) {
        printf("Stack is empty!\n");
        return -1;
    }
    
    return stack->top->data;
}

// удаление всего стека и освобождение памяти
void stackDelete(Stack* stack) {
    if (stack == NULL) {
        return;
    }
    
    // освобождаем все узлы
    while (stack->top != NULL) {
        Node* temp = stack->top;
        stack->top = stack->top->next;
        free(temp);
    }
    
    // освобождаем саму структуру стека
    free(stack);
}