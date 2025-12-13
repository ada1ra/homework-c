#include "hw_5-1_proBrackets.h"
#include "stack.h"
#include <stdio.h>
#include <string.h>

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
