#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "stack\stack.h"
#include "hw_5-2_sortStation\hw_5-2_sortStation.h"

// определение приоритета операторов
int precedence(char oper) {
    if (oper == '+' || oper == '-') {
        return 1;
    } else if (oper == '*' || oper == '/') {
        return 2;
    }
    return 0;
}

// преобразование инфиксного выражения в постфиксное
void infixToPostfix(const char* infix, char* postfix) {
    Stack* infixStack = stack_new();             // создаем стек для операторов
    int j = 0;                                   // индекс для записи в выходную строку
    
    // проходим по каждому символу входной строки
    for (int i = 0; infix[i] != '\0'; i++) {
        char current = infix[i];
        
        // если пробел, пропускаем
        if (current == ' ') {
            continue;
        }
        
        // если цифра, добавляем в выходную строку
        if (isdigit(current)) {
            postfix[j++] = current;
            postfix[j++] = ' ';                   // добавляем пробел после числа
        }
        // если открывающая скобка, помещаем ее в стек
        else if (current == '(') {
            stack_push(infixStack, current);
        }
        // если закрывающая скобка..
        else if (current == ')') {
            // извлекаем операторы из стека до открывающей скобки
            printf("1");
            while (infixStack != NULL && stack_peek(infixStack) != '(') {
                postfix[j++] = stack_pop(infixStack);
                postfix[j++] = ' ';
            }
            // удаляем открывающую скобку из стека
            printf("2");
            if (infixStack != NULL && stack_peek(infixStack) == '(') {
                stack_pop(infixStack);
            }
        }
        // если оператор (+, -, *, /)..
        else if (current == '+' || current == '-' || current == '*' || current == '/') {
            printf("3");
            // извлекаем операторы с более высоким или равным приоритетом
            while ((infixStack != NULL) && precedence(stack_peek(infixStack)) >= precedence(current)) {
                postfix[j++] = stack_pop(infixStack);
                postfix[j++] = ' ';
            }
            // помещаем текущий оператор в стек
            stack_push(infixStack, current);
        }
    }
    
    // извлекаем все оставшиеся операторы из стека
    while (infixStack != NULL) {
        postfix[j++] = stack_pop(infixStack);
        postfix[j++] = ' ';
    }
    
    // завершаем строку
    postfix[j] = '\0';
    
    // удаляем стек
    stack_delete(infixStack);
}

int main() {
    char infix[100];
    char postfix[100];
    
    printf("Введите инфиксное выражение (например, (1 + 1) * 2): ");
    fgets(infix, sizeof(infix), stdin);
    
    // удаляем символ новой строки, если он есть
    infix[strcspn(infix, "\n")] = 0;
    
    // преобразуем в постфиксную запись
    infixToPostfix(infix, postfix);
    
    printf("Постфиксная запись: %s\n", postfix);
    
    return 0;
}