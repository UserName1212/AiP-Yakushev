#include "functions.h"
#include "test.h"

int main() {
    setlocale(LC_ALL, "Rus"); //русский язык 

    printf("*****************Unit Tests*******************\n");
    run_tests();

    printf("\n*****************Task 1 (Calculator)*******************\n");
   
    double num1, num2;
    char op;
    printf("Введите выражение (например, 2 + 2) или 'q' для выхода:\n");

    while (1) {
        printf("Calc > ");
        int scan_res = scanf("%lf %c %lf", &num1, &op, &num2);
        if (scan_res != 3) {
            char c;
            while ((c = getchar()) != '\n' && c != EOF);
            break;
        }
        operation_t func = get_operation(op);
        if (func == NULL) {
            printf("Неизвестная операция '%c'. Попробуйте +, -, *, /, ^\n", op);
        }
        else {
            double res = func(num1, num2);
            printf("Результат: %.2lf\n", res);
        }
    }

    printf("\n*****************Task 2a (Сортировка целых чисел)*******************\n");
    
    int arrInt[] = { 5, 7, 3, -1, 2, 3 };
    int lenInt = sizeof(arrInt) / sizeof(arrInt[0]);
    printf("До сортировки: "); 
    printIntArray(arrInt, lenInt);
    universal_sort((void*)arrInt, lenInt, sizeof(int), swapInt, cmpInt);
    printf("После сортировки: "); 
    printIntArray(arrInt, lenInt);

    printf("\n*****************Task 2b (Сортировка вещественных чисел)*******************\n");
   
    double arrDbl[] = { 3.14, -5.5, 10.0, 0.0, 2.71 };
    int lenDbl = sizeof(arrDbl) / sizeof(arrDbl[0]);
    printf("До сортировки: "); 
    printDoubleArray(arrDbl, lenDbl);
    universal_sort((void*)arrDbl, lenDbl, sizeof(double), swapDouble, cmpDouble);
    printf("После сортировки: "); 
    printDoubleArray(arrDbl, lenDbl);

    printf("\n*****************Task 2c (Сортировка строк)*******************\n");
    
    char* arrStr[] = { "QQQ", "SDF", "ABC", "ZOO", "ANT" };
    int lenStr = sizeof(arrStr) / sizeof(arrStr[0]);
    printf("До сортировки: ");
    printStrArray(arrStr, lenStr);
    universal_sort((void*)arrStr, lenStr, sizeof(char*), swapStr, cmpStr);
    printf("После сортировки: ");
    printStrArray(arrStr, lenStr);

    printf("\n*****************Task 3 (вызов функций из массива указателей) ****************\n");
    string_func_t funcArray[5];  // Массив из 5 указателей на функции
    initStringFunctions(funcArray, 5);

    printf("Вызов функций из массива указателей:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d: %s\n", i + 1, funcArray[i]());
    }

    // Пример вызова конкретной функции из массива
    printf("\nПример вызова конкретной функции:\n");
    printf("Функция под индексом 2: %s\n", funcArray[2]());
    printf("Функция под индексом 0: %s\n", funcArray[0]());



#include <stdio.h>
#include <string.h>
#include <stdlib.h>

    // Определение структуры книги
    struct Book {
        char title[50];
        char author[50];
        char category[50];
        int year;
        double price;
    };

    
    // Задание 4. Структуры

    printf("\n*****************Task 4*****\n");
    struct Book staticBook;
    // Выделение памяти для динамической книги
    struct Book* dynamicBook = (struct Book*)malloc(sizeof(struct Book));
    if (dynamicBook == NULL) {
        printf("Ошибка выделения памяти!\n");
        return 1;
        }

    // Заполнение статической книги
    // Используем snprintf для безопасного копирования строк
    snprintf(staticBook.title, sizeof(staticBook.title), "%s", "Спортивное программирование");
    snprintf(staticBook.author, sizeof(staticBook.author), "%s", "Стивен Халим");
    snprintf(staticBook.category, sizeof(staticBook.category), "%s", "Литература победителей");
    staticBook.year = 2020;
    staticBook.price = 42.42;

    // Заполнение динамической книги
    snprintf(dynamicBook->title, sizeof(dynamicBook->title), "%s", "Стив Джобс");
    snprintf(dynamicBook->author, sizeof(dynamicBook->author), "%s", "Уолтер Айзексон");
    snprintf(dynamicBook->category, sizeof(dynamicBook->category), "%s", "Биография");
    dynamicBook->year = 2011;
    dynamicBook->price = 19.84;

    // Задание 4г. Вывод информации о книгах
    printf("Вывод статической книги:\n");
    printBook(&staticBook);

    printf("Вывод динамической книги:\n");
    printBook(dynamicBook);

    // Освобождение памяти
    free(dynamicBook);

    return 0;
}