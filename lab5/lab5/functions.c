#include "functions.h"

// --- Задание 1. Указатель на функцию. "Калькулятор" ---
    // Напишите функции:
    // 1) sum - принимает два значения типа double и возвращает сумму
    // 2) sub - разность
    // 3) mul - произведение
    // 4) div - результат деления
    // 5) возведение в степень - можно воспользоваться pow() из <math.h>
    // не забудьте unit-тесты

    // Сделайте интерфейс калькулятора.
    // Пока пользователь хочет пользоваться калькулятором,
    // он может вводить два значения и знак операции;
    // результат выводится на экран.
    // Если ввод некорректный, нужно сообщить об этом пользователю и продолжить работу
double sum(double a, double b) {
    return a + b;
}

double sub(double a, double b) {
    return a - b;
}

double mul(double a, double b) {
    return a * b;
}

double dv(double a, double b) {
    if (b == 0.0) {
        printf("Ошибка: деление на ноль!\n");
        return 0.0;
    }
    return a / b;
}

double pwr(double a, double b) {
    return pow(a, b);
}

operation_t get_operation(char op) {
    switch (op) {
    case '+': return sum;
    case '-': return sub;
    case '*': return mul;
    case '/': return dv;
    case '^': return pwr;
    default: return NULL; 
    }
}

//Задание 2.
// --- Задание 2. Указатель на функцию в качестве аргумента ---
    // 2а. Реализуйте функцию сортировки любых объектов sort, которая принимает следующие параметры:
    // 1) указатель на первый сортируемый элемент (void*)
    // 2) количество сортируемых элементов
    // 3) размер элемента в байтах
    // 4) указатель на функцию перестановки элементов, которая принимает на вход два значения типа void*
    // 5) указатель на функцию сравнения элементов, которая принимает также два указателя и возвращает short

    // В качестве примера напишите функцию swapInt перестановки двух целых чисел
    // (принимает два указателя на void и меняет значения местами)
    // и функцию cmpInt, которая принимает два void указателя и
    // возвращает тип short - результат сравнения:
    // <0 - первый элемент меньше, чем второй
    // =0 - равны
    // >0 - первый элемент больше, чем второй

    // Пример использования:
    /*
    {
        int a = {5, 7, 3, -1, 2, 3};
        int aLen = 6;
        sort((void*)a, aLen, sizeof(int), swapInt, cmpInt);
    }
    */

    // Задание 2б. По аналогии с 8а создайте вспомогательные
    // функции swapDouble и cmpDouble. Примените функцию sort
    // для сортировки массива вещественных значений.

    // Задание 2в. По аналогии с 8а создайте вспомогательные
    // функции - swapStr и cmpStr; вызовите функцию Sort
    // для сортировки массива указателей на строки.
    //  char* arStr[] = {"QQQ", "SDF", "ABC"...};
    
// Сортировка пузырьком
void universal_sort(void* base, int num, int size, swap_func_t swap, cmp_func_t cmp) {
    char* ptr = (char*)base; // Приводим к char*, чтобы шагать по байтам
    for (int i = 0; i < num - 1; i++) {
        for (int j = 0; j < num - i - 1; j++) {
            void* p1 = ptr + j * size;
            void* p2 = ptr + (j + 1) * size;
            if (cmp(p1, p2) > 0) {
                swap(p1, p2);
            }
        }
    }
}

// 2a. Для int
void swapInt(void* a, void* b) {
    int temp = *(int*)a;
    *(int*)a = *(int*)b;
    *(int*)b = temp;
}

short cmpInt(void* a, void* b) {
    int val1 = *(int*)a;
    int val2 = *(int*)b;
    if (val1 < val2) return -1;
    if (val1 > val2) return 1;
    return 0;
}

// 2b. Для double
void swapDouble(void* a, void* b) {
    double temp = *(double*)a;
    *(double*)a = *(double*)b;
    *(double*)b = temp;
}

short cmpDouble(void* a, void* b) {
    double val1 = *(double*)a;
    double val2 = *(double*)b;
    // Для простоты сравниваем напрямую, без эпсилон
    if (val1 < val2) return -1;
    if (val1 > val2) return 1;
    return 0;
}

// 2c. Для строк
void swapStr(void* a, void* b) {
    char* temp = *(char**)a;
    *(char**)a = *(char**)b;
    *(char**)b = temp;
}

short cmpStr(void* a, void* b) {
    char* s1 = *(char**)a;
    char* s2 = *(char**)b;
    int res = strcmp(s1, s2);
    if (res < 0) return -1;
    if (res > 0) return 1;
    return 0;
}

void printIntArray(int* arr, int size) {
    printf("[ ");
    for (int i = 0; i < size; i++) printf("%d ", arr[i]);
    printf("]\n");
}

void printDoubleArray(double* arr, int size) {
    printf("[ ");
    for (int i = 0; i < size; i++) printf("%.1f ", arr[i]);
    printf("]\n");
}

void printStrArray(char** arr, int size) {
    printf("[ ");
    for (int i = 0; i < size; i++) printf("\"%s\" ", arr[i]);
    printf("]\n");
}
#include "functions.h"

//задание 3
const char* getGreeting() {
    return "Привет, мир!";  
}
const char* getFarewell() {
    return "До свидания!";
}
const char* getCurrentTime() {
    return "Текущее время: 14:30 (пример)";
}

const char* getRandomFact() {
       return "Факт: Земля вращается вокруг Солнца.";
}
const char* getErrorMessage() {
    return "Ошибка: что-то пошло не так!";
}

void initStringFunctions(string_func_t* funcArray, int size) {
    if (size < 5) {
        printf("Предупреждение: массив слишком мал для инициализации!\n");
        return;
    }
    funcArray[0] = getGreeting;
    funcArray[1] = getFarewell;
    funcArray[2] = getCurrentTime;
    funcArray[3] = getRandomFact;
    funcArray[4] = getErrorMessage;
}



//задание 4
void printBook(const struct Book* book) {
    if (book == NULL) {
        printf("Передана несуществующая книга\n");
        return;
    }
    printf("Автор: %s\n", book->author);
    printf("Название: %s\n", book->title);
    printf("Год публикации: %d\n", book->year);
    printf("Цена: %.2f\n", book->price);
    printf("Категория: %s\n", book->category);
    printf("\n");
}