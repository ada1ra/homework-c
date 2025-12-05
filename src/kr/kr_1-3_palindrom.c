#include <string.h>
#include <stdio.h>
#define MAX_SIZE 100

int isPal(int num) {
    char binNum[MAX_SIZE];
    int count = 0;
    while (num > 0) {
        if (num % 2 == 1) {
            num = num / 2;
            binNum[count] = 1;
        } else {
            num = num / 2;
            binNum[count] = 0;
        }

        //printf("%d", binNum[count]);
        count = count + 1;
    }

    for (int i = 0; i <= count; i++) {
        if (binNum[i] == binNum[count - i])
            return 0;
    }

    return 1;
}


int main(void)
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int result = isPal(i);
        if (result == 1)
            printf("%d\n", i);
    }
    return 0;
}
