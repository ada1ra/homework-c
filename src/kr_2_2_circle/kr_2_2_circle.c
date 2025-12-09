#include <stdio.h>

int main()
{
    int N, bits[32];
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
        scanf("%d", &bits[i]);

    int max_val = 0;

    // перебираем все начальные позиции для сдвига
    for (int start = 0; start < N; start++) {
        int current = 0;

        // собираем число с позиции start
        for (int i = 0; i < N; i++) {
            int idx = (start + i) % N;
            current = (current << 1) | bits[idx]; // добавляем бит
        }

        if (current > max_val) {
            max_val = current;
        }
    }

    printf("%d\n", max_val);
    return 0;
}
