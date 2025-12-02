#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include<time.h>
#define N 3
#define M 3
#define K 6
#define SWAP(a,b) { int tmp = a; a = b; b = tmp; }
int bin_search(int arr[], int left, int right, int x); 

int main()
{
    srand(time(NULL));
    // Задание 1. Объявите трехмерный статический N*M*K массив и сформируйте указанные
    // значения элементов следующим образом:
    // а) проинициализируйте массив при объявлении
    // б) объявите неинициализированный массив и присвойте значения элементам
    //	с помощью кода
    //					 |--------|
    //				   / |3  3  3 |
    //     			 |---------|3 |
    //			   / | 2  2  2 |3 |
    //			  |---------|2 |__|
    //			  | 1  1  1 |2 | /
    //			  | 1  1  1 |__|
    //			  | 1  1  1 | /
    //			  |_________|
    //
    // в) найдите сумму элементов массива
    //а 
    int arr[N][M][K]; //  =
    /*{
        {
            {1, 1, 1},
            {1, 1, 1},
            {1, 1, 1}
        },
        {
            {2, 2, 2},
            {2, 2, 2},
            {2, 2, 2}
        },
        {
            {3, 3, 3},
            {3, 3, 3},
            {3, 3, 3}
        }
    };*/
    //б
    int arr1[N][M][K];
    for (int z = 0; z < K; z++) {
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                arr1[j][i][z] = j + 1;
            }
        }
    }
    //в
    int summ = 0;
    for (int z = 0; z < K; z++) {
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                summ += arr1[j][i][z];
            }
        }
    }
    // Задание 2.1 Создайте динамический двухмерный массив с размерностями,
    // вычисляемыми в процессе выполнения программы - N*M.
    // Задайте значения элементов помощью генератора [псевдо]случайных чисел.
    // Найдите  сумму элементов.
    // Подсказка: для генерации [псевдо]случайных чисел используйте функцию
    // стандартной библиотеки rand() (<stdlib.h>)
    // Задание 2.2 В сформированном массиве отсортируйте каждую строку по
    // убыванию значений. Используйте сортировку "выбором"

    // Задание 2.3 Объявите одномерный массив размерностью N.
    // Присвойте i-му элементу одномерного массива
    // среднее значение элементов i-ой строки двухмерного массива
    // 
    //2.1
    int row = 3; //количество строк
    int col = 7;//количество столбцы
    int** din_arr = (int**)malloc(row * sizeof(int*));
    for (int i = 0; i < row; i++)
    {
        din_arr[i] = (int*)malloc(col * sizeof(int));
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            din_arr[i][j] = rand() % 100;
            printf("%d ", din_arr[i][j]);
        }
        printf("\n");
    }

    //2.2
    for (int i = 0; i < row; i++)
    {
        int* line = din_arr[i];
        for (int j = 0; j < col - 1; j++)
        {
            int max_idx = j;
            for (int k = j + 1; k < col; k++)
            {
                if (line[k] > line[max_idx])
                {
                    max_idx = k;
                }
            }
            if (max_idx != j) {
                SWAP(line[j], line[max_idx]);
            }
        }
    }

    printf("\n\n");

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d ", din_arr[i][j]);
        }
        printf("\n");
    }

    //2.3
    int* sr_arr = (int*)malloc(row * sizeof(int));
    for (int i = 0; i < row; i++) {
        int summ = 0;
        for (int j = 0; j < col; j++) {
            summ += din_arr[i][j];
        }
        sr_arr[i] = summ / col;
        printf("%d ", sr_arr[i]);
    }


    for (int i = 0; i < row; i++) {
        free(din_arr[i]);
    }
    free(din_arr);
    free(sr_arr);




    // Задание 3.1 Напишите фрагмент кода, который вводит N целых чисел с
    // клавиатуры в объявленный Вами встроенный одномерный массив, каждый раз
    // упорядочивая полученный на предыдущем шаге массив по возрастанию и выводя на экран

    // Задание 3.2 Простой поиск.
    // Модифицируйте предыдущее задание следующим образом: очередное значение
    // вводится в массив только при условии, что там еще такого нет (т.е. дубли игнорируются)
    int n;
    printf("\nEnter the number of numbers: ");
    scanf_s("%d", &n);

    int arr4[100];
    int size = 0;
    int i = 0;
    while (i < n)
    {
        int found = 0; //3.2
        int x;
        printf("\nEnter number: ");
        scanf_s("%d", &x);

        found = bin_search(arr4, 0, size, x);
        if (!found)
        {
            arr4[size] = x;
            for (int j = size; j >= 0; j--)
            {
                if (arr4[j] < arr4[j - 1])
                {
                    SWAP(arr4[j], arr4[j - 1]);
                }
            }
            size++;
            i++;
        }

        printf("Current array: ");
        for (int j = 0; j < size; j++)
        {
            printf("%d ", arr4[j]);
        }
        printf("\n");

    }
    return 0;
}

int bin_search(int arr[], int left, int right, int x) {
    if (left > right) {
        return 0;      
    }     

    int mid = left + (right - left) / 2;
    if (arr[mid] == x) {
        printf("Duplicate!!!!\n");
        return 1;
    }
    else if (arr[mid] < x)
        return bin_search(arr, mid + 1, right, x);
    else
        return bin_search(arr, left, mid - 1, x);
}




    // Задание 4. Напишите программу, которая
    // вводит строки с клавиатуры в двумерный встроенный массив 5*80 элементов типа char;
    // признаком конца ввода является символ * (то есть строка - "*") или
    // заполнение массива (больше свободных строк нет);
    // затем производится сортировка строк в алфавитном порядке.
    // Пояснение: не следует для сортировки сложных объектов физически
    // перемещать их в памяти. Намного эффективнее завести массив
    // указателей на соответствующие строки и перемещать только указатели.

    // Подсказка: для лексиграфического сравнения строк пользуйтесь
    // функцией стандартной библиотеки strcmp(...) (<string.h>).

