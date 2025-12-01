#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// функция для определения необходимого количества бит (двоичное представление зависит от количества бит)
int calculateRequiredBits(int num1, int num2)
{
    int max_abs = 0;

    // находим максимальное по модулю число из двух
    if (abs(num1) > abs(num2)) {
        max_abs = abs(num1);
    } else {
        max_abs = abs(num2);
    }

    // вычисляем сумму (для определения возможного переполнения)
    long long sum = (long long)num1 + num2;

    // находим максимальное значение из трёх: |num1|, |num2|, |sum|
    if (abs(sum) > max_abs) {
        max_abs = abs(sum);
    }

    // вычисляем необходимое количество бит
    int bits_needed = 0;
    while ((1LL << bits_needed) <= max_abs * 2LL) {
        bits_needed++;
    }

    // минимальное количество бит
    if (bits_needed < 4) {
        bits_needed = 4;
    }

    // ограничим максимальное количество бит для нормального вывода
    if (bits_needed > 32) {
        bits_needed = 32;
    }

    return bits_needed;
}

// функция для перевода десятичного числа в двоичную строку (8-битное представление)
char* decimalToBinary(int num, int bits)
{
    // выделяем память для строки: bits символов + 1 для завершающего нуля
    char* binary = (char*)malloc(bits + 1);
    if (binary == NULL) {
        return NULL;
    }

    // заполняем строку нулями
    for (int i = 0; i < bits; i++) {
        binary[i] = '0';
    }
    binary[bits] = '\0'; // завершаем строку

    // обрабатываем отрицательные числа (дополнительный код)
    unsigned int unsigned_num;
    if (num < 0) {
        // для отрицательных чисел используем дополнительный код
        unsigned_num = (1 << bits) + num; // 2^bits + num
    } else {
        unsigned_num = num;
    }

    // преобразуем в двоичный вид
    for (int i = bits - 1; i >= 0; i--) {
        binary[i] = (unsigned_num & 1) ? '1' : '0';
        unsigned_num >>= 1; // сдвигаем вправо для проверки следующего бита
    }

    return binary;
}

// функция для сложения двух двоичных чисел (строк) в столбик
char* addBinaryStrings(const char* bin1, const char* bin2, int bits)
{
    char* result = (char*)malloc(bits + 1);
    if (result == NULL) {
        return NULL;
    }

    int carry = 0; // перенос
    // проходим от младшего бита к старшему
    for (int i = bits - 1; i >= 0; i--) {
        int bit1 = bin1[i] - '0';
        int bit2 = bin2[i] - '0';
        int sum = bit1 + bit2 + carry;

        // текущий бит результата
        result[i] = (sum % 2) + '0';
        // вычисляем перенос для следующего бита
        carry = sum / 2;
    }

    result[bits] = '\0'; // завершаем строку
    return result;
}

// функция для перевода двоичной строки в десятичное число
int binaryToDecimal(const char* binary, int bits)
{
    int result = 0;

    // если число положительное (старший бит = 0)
    if (binary[0] == '0') {
        for (int i = 0; i < bits; i++) {
            result = result * 2 + (binary[i] - '0');
        }
    }
    // если число отрицательное (старший бит = 1, дополнительный код)
    else {
        // инвертируем все биты
        int inverted = 0;
        for (int i = 0; i < bits; i++) {
            inverted = inverted * 2 + (binary[i] == '0' ? 1 : 0);
        }
        // добавляем 1 и берем со знаком минус
        result = -(inverted + 1);
    }

    return result;
}

int main()
{
    int num1, num2;

    printf("Введите первое число: ");
    scanf("%d", &num1);
    printf("Введите второе число: ");
    scanf("%d", &num2);

    printf("\n");

    // автоматически определяем необходимое количество бит
    int bits = calculateRequiredBits(num1, num2);

    // перевод чисел в двоичный вид
    char* bin1 = decimalToBinary(num1, bits);
    char* bin2 = decimalToBinary(num2, bits);
    if (bin1 == NULL || bin2 == NULL) {
        printf("Ошибка выделения памяти\n");
        return 1;
    }

    // вывод двоичных представлений
    printf("Первое число в двоичном представлении в дополнительном коде: %s\n", bin1);
    printf("Второе число в двоичном представлении в дополнительном коде: %s\n\n", bin2);

    // сложение в двоичном виде
    char* binarySum = addBinaryStrings(bin1, bin2, bits);
    if (binarySum == NULL) {
        printf("Ошибка выделения памяти\n");
        free(bin1);
        free(bin2);
        return 1;
    }

    // вывод суммы в двоичном виде
    printf("Сумма в двоичном коде: %s\n", binarySum);

    // перевод суммы в десятичное
    int decimalSum = binaryToDecimal(binarySum, bits);

    // вывод суммы в десятичном виде
    printf("Сумма в десятичном виде: %d\n", decimalSum);

    // освобождаем память
    free(bin1);
    free(bin2);
    free(binarySum);

    return 0;
}
