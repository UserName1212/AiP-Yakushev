#pragma once
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <time.h>
#include <stdarg.h>


#define ROWS 3
#define COLS 3

void swap(int* i, int* j);
int MyMin(int arr[][COLS], int rows, int cols); 
int DynamicMyMin(int** d_arr, int rows, int cols);
int PrintArr(int** d_arr, int rows, int cols); 
int myStrCmp(const char* str1, const char* str2);
void addArr(int** arr, int* size, int x);
void printAr(int arr[], int size);
int summN(int n);
int fib(int n);
void varArgs(int first, ...);
void varArgsMod(int first, ...);
int* myMin(int* arr, int size);

enum DayType
{
    MON,
    TUE,
    WED,
    THU,
    FRI,
    SAT,
    SUN,
};
int isLeap(unsigned year);
int transfrom(
    unsigned year,
    unsigned month,
    unsigned day,
    unsigned* nWeek,
    enum DayType* dayType);
