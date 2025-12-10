#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// объединение для доступа к битам (записываем число в value, читаем биты через bits)
typedef union {
    double value;
    uint64_t bits; // unsigned long long (64 bits)
} DoubleConverter;

// преобразование double в экспоненциальный формат (sm*2^p)
char* doubleExponential(double number)
{
    DoubleConverter converter;
    converter.value = number;

    // извлекаем биты знака, порядка и мантиссы
    uint64_t bits = converter.bits;
    int sign_bit = (bits >> 63) & 1; // извлекаем знак (1бит)
    int exponent_bits = (bits >> 52) & 0x7FF; // извлекаем порядок (11 бит)
    uint64_t mantissa_bits = bits & 0xFFFFFFFFFFFFF; // извлекаем мантиссу (52 бита)

    // вычисляем реальный порядок
    int exponent;
    if (exponent_bits == 0) {
        // денормализованное число (для него фиксированная экспонента -1022)
        exponent = -1022;
    } else {
        // нормализованное число (вычисляем смещение на 1023)
        exponent = exponent_bits - 1023;
    }

    // создаем буфер для результата
    char* result = (char*)malloc(256); // достаточно большой буфер
    if (result == NULL) {
        return NULL; // ошибка выделения памяти
    }

    int pos = 0; // позиция в буфере

    // выводим знак
    result[pos++] = sign_bit ? '-' : '+';

    // выводим целую часть мантиссы
    if (exponent_bits == 0) {
        // для денормализованных чисел целая часть 0
        result[pos++] = '0';
    } else {
        // для нормализованных чисел целая часть 1
        result[pos++] = '1';
    }

    // преобразуем дробную часть мантиссы в строку цифр
    uint64_t remainder = mantissa_bits;
    char decimal_digits[21]; // массив для хранения 20 цифр + 1 для округления
    int digit_count = 0;

    // генерируем 21 цифру (20 для вывода + 1 для округления)
    for (int i = 0; i < 21; i++) {
        remainder *= 10;
        uint64_t digit = remainder >> 52; // деление на 2^52
        remainder &= ((uint64_t)1 << 52) - 1; // остаток от деления на 2^52
        decimal_digits[i] = (char)('0' + digit);
        digit_count++;

        // останавливаемся, если остаток стал 0
        if (remainder == 0)
            break;
    }

    // если сгенерировано 21 цифр, выполняем округление
    if (digit_count == 21) {
        // округляем 20-ю цифру на основе 21-й
        int round_pos = 19;
        while (round_pos >= 0 && decimal_digits[round_pos + 1] >= '5') {
            if (decimal_digits[round_pos] < '9') {
                decimal_digits[round_pos]++;
                break;
            } else {
                decimal_digits[round_pos] = '0';
                round_pos--;
            }
        }

        digit_count = 20; // оставляем 20 цифр
    }

    // удаляем незначащие нули с конца
    while (digit_count > 0 && decimal_digits[digit_count - 1] == '0') {
        digit_count--;
    }

    // выводим дробную часть, если есть значащие цифры
    if (digit_count > 0) {
        result[pos++] = '.';
        for (int i = 0; i < digit_count; i++) {
            result[pos++] = decimal_digits[i];
        }
    }

    // выводим порядок
    result[pos++] = '*';
    result[pos++] = '2';
    result[pos++] = '^';

    // преобразуем порядок в строку
    char exponent_str[12]; // достаточно для int
    sprintf(exponent_str, "%d", exponent);
    int exp_len = strlen(exponent_str);
    for (int i = 0; i < exp_len; i++) {
        result[pos++] = exponent_str[i];
    }

    result[pos] = '\0'; // завершаем строку

    return result;
}

int main()
{
    double number;
    printf("Enter a number: ");
    scanf("%lf", &number);

    // получаем строку с результатом
    char* result = doubleExponential(number);

    if (result != NULL) {
        // выводим результат
        printf("Result: %s\n", result);

        // освобождаем память
        free(result);
    } else
        printf("Memory allocation error\n");

    return 0;
}