#ifndef SORTSTATION_H
#define SORTSTATION_H

// преобразование инфиксного выражения в постфиксное
void infixToPostfix(const char* infix, char* postfix);

// проверка приоритета операторов
int precedence(char op);

// ввод данных и вывод результата
int main(void);

#endif