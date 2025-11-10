#include "hw_5-2_sortStation.h"
#include "stack.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
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
