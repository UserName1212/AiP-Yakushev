#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <locale.h>

//Задание 1
double sum(double a, double b);   
double sub(double a, double b);  
double mul(double a, double b);  
double dv(double a, double b);   
double pwr(double a, double b);  

typedef double (*operation_t)(double, double);

operation_t get_operation(char op);

//Задание 2
typedef void (*swap_func_t)(void* a, void* b);
typedef short (*cmp_func_t)(void* a, void* b);

//сортировка
void universal_sort(void* base, int num, int size, swap_func_t swap, cmp_func_t cmp);

//2a. Для int
void swapInt(void* a, void* b);
short cmpInt(void* a, void* b);

//2b. Для double
void swapDouble(void* a, void* b);
short cmpDouble(void* a, void* b);

//2c. Для строк (char*)
void swapStr(void* a, void* b);
short cmpStr(void* a, void* b);

void printIntArray(int* arr, int size);
void printDoubleArray(double* arr, int size);
void printStrArray(char** arr, int size);

//3 
const char* getGreeting();
const char* getFarewell();
const char* getCurrentTime();  
const char* getRandomFact();   
const char* getErrorMessage(); 
typedef const char* (*string_func_t)(void);
void initStringFunctions(string_func_t* funcArray, int size);

//4
struct Book {
    char author[50];
    char title[50];
    char category[50];
    int year;
    double price;
};
void printBook(const struct Book* book);