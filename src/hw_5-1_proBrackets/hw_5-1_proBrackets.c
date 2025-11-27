#include "hw_5-1_proBrackets/hw_5-1_proBrackets.h"
#include "stack/stack.h"
#include <stdio.h>
#include <string.h>

int isValidBrackets(char originalString[])
{
    Stack* bracketsStack = stackNew();

    for (int i = 0; i < strlen(originalString); i++) {
        char s = originalString[i];

        if ((s == '(') || (s == '{') || (s == '[')) {
            stackPush(bracketsStack, s);

        } else if ((s == ')' && bracketsStack == NULL)
            || (s == '}' && bracketsStack == NULL)
            || (s == ']' && bracketsStack == NULL)) {
            return 0;

        } else if ((s == ')' && stackPeek(bracketsStack) == '(')
            || (s == '}' && stackPeek(bracketsStack) == '{')
            || (s == ']' && stackPeek(bracketsStack) == '[')) {
            stackPop(bracketsStack);

        } else {
            return 0;
        }
    }
    if (bracketsStack != NULL && bracketsStack->top != NULL) {
        return 0;
    }
    return 1;
}

int main(void)
{
    char originalString[100];
    scanf("%99s", originalString);
    int result = isValidBrackets(originalString);

    if (result == 0) {
        printf("String doesn't follow rules.\n");
        return -1;
    }
    printf("Balance of brackets is keep.\n");
    return 0;
}
