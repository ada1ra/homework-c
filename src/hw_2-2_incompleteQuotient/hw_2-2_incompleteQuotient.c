#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int a;
    int b;
    int quotient = 0;
    scanf("%d", &a);
    scanf("%d", &b);

    if (b == 0) {
        printf("Ошибка: деление на 0\n");
        return -1;
    }

    while ((quotient + 1) * abs(b) <= abs(a))
        quotient++;

    if (a * b < 0)
        quotient = -quotient;

    printf("Неполное частное = %d", quotient);
    return 0;
}
