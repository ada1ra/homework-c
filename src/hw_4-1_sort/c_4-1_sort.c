#include <stdio.h>

extern int sort(int* arr, int n);

int main()
{
    int arr[100];
    int n = 0;
    int num;
    char c;

    // сохранение чисел в массив до 100 или до конца строки (т.к. в условии "не более 100")
    while (n < 100) {
        // пытаемся прочитать число
        int result = scanf("%d", &num);
        if (result == 1) {
            arr[n] = num;
            n++;
        } else {
            // если не число, проверяем конец строки
            scanf("%c", &c);
            if (c == '\n')
                break;
            continue;
        }

        // проверяем следующий символ
        int next_char = getchar();
        if (next_char == '\n') {
            break; // если конец строки - завершаем ввод
        }
        if (next_char != EOF) {
            ungetc(next_char, stdin); // возвращаем символ обратно в поток
        }
    }
    int changed = sort(arr, n);

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\n");

    return changed;
}
