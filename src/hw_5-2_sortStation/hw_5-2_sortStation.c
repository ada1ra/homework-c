#include "hw_5-2_sortStation.h"
#include "stack.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// определение приоритета операторов
int precedence(char oper)
{
    if (oper == '+' || oper == '-') {
        return 1;
    } else if (oper == '*' || oper == '/') {
        return 2;
    }
    return 0;
}

// преобразование инфиксного выражения в постфиксное
void infixToPostfix(const char* infix, char* postfix)
{
    Stack* infixStack = stackNew(); // создаем стек для операторов
    int j = 0; // индекс для записи в выходную строку

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
            postfix[j++] = ' '; // добавляем пробел после числа
        }
        // если открывающая скобка, помещаем ее в стек
        else if (current == '(') {
            stackPush(infixStack, current);
        }
        // если закрывающая скобка..
        else if (current == ')') {
            // извлекаем операторы из стека до открывающей скобки
            while (infixStack != NULL && infixStack->top != NULL && stackPeek(infixStack) != '(') {
                postfix[j++] = stackPop(infixStack);
                postfix[j++] = ' ';
            }
            // удаляем открывающую скобку из стека
            if (infixStack != NULL && infixStack->top != NULL && stackPeek(infixStack) == '(') {
                stackPop(infixStack);
            }
        }
        // если оператор (+, -, *, /)..
        else if (current == '+' || current == '-' || current == '*' || current == '/') {
            // извлекаем операторы с более высоким или равным приоритетом
            while ((infixStack != NULL && infixStack->top != NULL) && precedence(stackPeek(infixStack)) >= precedence(current)) {
                postfix[j++] = stackPop(infixStack);
                postfix[j++] = ' ';
            }
            // помещаем текущий оператор в стек
            stackPush(infixStack, current);
        }
    }

    // извлекаем все оставшиеся операторы из стека
    while (infixStack != NULL && infixStack->top != NULL) {
        postfix[j++] = stackPop(infixStack);
        postfix[j++] = ' ';
    }

    // завершаем строку
    postfix[j] = '\0';

    // удаляем стек
    stackDelete(infixStack);
}
