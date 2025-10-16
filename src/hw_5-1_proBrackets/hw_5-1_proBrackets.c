#include <stdio.h>
#include <string.h>
#include "stack\stack.h"
#include "hw_5-2_sortStation\hw_5-2_sortStation.h"

int isValidBrackets(char originalString[]){
    Stack* bracketsStack = stack_new();

    for (int i = 0; i < strlen(originalString); i++) {
        char s = originalString[i];
        
        if ((s == '(') || (s == '{') || (s == '[')) {
            stack_push(bracketsStack, s);
            
        } else if ((s == ')' && bracketsStack == NULL) ||
                   (s == '}' && bracketsStack == NULL) ||
                   (s == ']' && bracketsStack == NULL)) {
            //printf("String doesn't follow rules.\n");
            return 0;

        } else if ((s == ')' && stack_peek(bracketsStack) == '(') ||
                   (s == '}' && stack_peek(bracketsStack) == '{') ||
                   (s == ']' && stack_peek(bracketsStack) == '[')) {
            stack_pop(bracketsStack);

        } else {
            //printf("String doesn't follow rules.\n");
            return 0;
        }
    }
    if (bracketsStack != NULL && bracketsStack->top != NULL) {
        //printf("String doesn't follow rules.\n");
        return 0;
    }
    //printf("Balance of brackets is keep.\n");
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
