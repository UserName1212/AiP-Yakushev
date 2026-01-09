#include <stdio.h>

// собственные заголовочные файлы
#include "useful_constants.h"

int main()
{
    // указатели (pointers)
    {
        int a = 0, b = 1, c = 2;
        int *pa = &a; // тип - указатель на int
        int *pb = &b;
        int *pc = &c;
        int **ppa = &pa;
        int **ppb = &pb;

        b = *pc;
        b = **ppa;
        pb = pc;
        c = b;

        void *pv; // any data type
        int *converted = (int *)pv;
    }

    // https://prog-cpp.ru/c-input-output

    printf("%d\n", 1);

    int i, j;
    // scanf("%d", &i);
    // printf("i=%d\n", i);
    // printf("i<<1=%d\n", i << 1); // for j ...
    // переносы строк: здесь важны

    // шестнадцатеричные коды
    unsigned hex = 0xAB00;

    // ternary operator
    int a = i > 5 ? i : -i;

// macro (директивы препроцессора)
#define CONST_NAME (666)
    a = CONST_NAME * 2;

// а здесь важно не ставить пробел перед скобкой
#define EXPRESSION_NAME(x, y) ((x) + 2 * (y))

    int b = EXPRESSION_NAME(i, j);

    // директивы условной трансляции

#if defined NAME
    b++;
#endif

#ifdef NAME
    b++;
#elif defined ANOTHER_NAME
    b += 2;
#else
    b--;
#endif

    // побитовые операции
    // https://learn.microsoft.com/ru-ru/cpp/c-language/c-bitwise-operators
    {
        int a = 1, b = 1, c = 0;
        printf("%d\n", a & c);

        // xor (исключающее или): помните таблицу истинности?
        printf("%d\n", 0xABCD ^ 0x1234);

        // Не (not): логическое ! побитовое ~
    }
}
