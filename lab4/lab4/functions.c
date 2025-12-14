#include "functions.h"

void swap(int* i, int* j) 
{
    int t = *i;
    *i = *j;
    *j = t;
}
int MyMin(int arr[][COLS], int rows, int cols) 
{
    int min = arr[0][0]; 
    for (int i = 0; i < rows; i++) 
        for(int j = 0; j<cols; j++)
            if (arr[i][j] < min)
                min = arr[i][j];
    return(min); 
}
int DynamicMyMin(int** d_arr, int rows, int cols)
{
    int min = d_arr[0][0];
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (d_arr[i][j] < min)
                min = d_arr[i][j];
    return min; 
}
int PrintArr(int** d_arr, int rows, int cols)
{
    printf("dynamic array: \n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            printf("%d ", d_arr[i][j]);
        printf("\n"); 
    }
}
int myStrCmp(const char* str1, const char* str2) 
{
    while (*str1 && (*str1 == *str2)) 
    {  
        str1++;
        str2++;
    }
    return (unsigned char)(*str1) - (unsigned char)(*str2);
}
void addArr(int** arr, int* size, int x)
{
    for (int i = 0; i < *size; i++)
    {
        if ((*arr)[i] == x) return;
    }
    int newsize = *size + 1;
    int* temp = realloc(*arr, newsize * sizeof(int));
    if (temp == NULL) return;

    *arr = temp;
    (*arr)[newsize - 1] = x;    
    (*size)++;
}
void printAr(int arr[], int size) 
{
    printf("Array: ");
    for (int i = 0; i < size; i++) 
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int summN(int n)
{ 
    if (n == 1)
        return 1; 
    return n + summN(n - 1); 
}
int fib(int n) 
{
    if (n == 0)
        return 0; 
    if (n == 1)
        return 1; 
    return fib(n - 1) + fib(n - 2); 
}

void varArgs(int first, ...)
{
    int* p = &first;   
    int count = 0;

    printf("Args: ");

    while (*p != 0)
    {
        printf("%d ", *p);
        count++;
        p++;           
    }

    printf("\nCount: %d\n\n", count);
}




void varArgsMod(int first, ...)
{
    va_list args;
    int count = 0;
    int value;

    printf("Args: ");

    va_start(args, first);
        value = first;
    while (value != 0)
    {
        printf("%d ", value);
        count++;
        value = va_arg(args, int);
    }
    va_end(args);
    printf("\nCount: %d\n\n", count);
}

int* myMin(int* arr, int size) 
{
    int* min = arr;   
    for (int i = 1; i < size; i++)
    {
        if (arr[i] < *min)
        {
            min = &arr[i];
        }
    }
    return min;
}

int isLeap(unsigned year)
{
    return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}

int transfrom(
    unsigned year,
    unsigned month,
    unsigned day,
    unsigned* nWeek,
    enum DayType* dayType)
{
    if (!nWeek || !dayType || month < 1 || month > 12)
        return -1;

    unsigned daysInMonth[] =
    {
        31, 28, 31, 30, 31, 30,
        31, 31, 30, 31, 30, 31
    };

    if (isLeap(year))
        daysInMonth[1] = 29;

    if (day < 1 || day > daysInMonth[month - 1])
        return -1;

    unsigned dayOfYear = day;
    for (unsigned i = 0; i < month - 1; i++)
        dayOfYear += daysInMonth[i];

    unsigned totalDays = 0;

    for (unsigned y = 1900; y < year; y++)
        totalDays += isLeap(y) ? 366 : 365;

    totalDays += dayOfYear - 1;

    *dayType = (enum DayType)(totalDays % 7);

    
    *nWeek = (dayOfYear - 1) / 7 + 1;

    return 0;
}
