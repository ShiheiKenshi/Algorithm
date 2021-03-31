#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void swapInt(int *a, int *b)
{
    int temp = *a;
    *a=*b;
    *b=temp;
}

void swapDbl(double *a, double *b)
{
    double temp = *a;
    *a=*b;
    *b=temp;
}

void printDblArray (double* array, int size)
{
    for (int i=0; i<size; ++i)
    {
        printf ("[%lf]", array[i]);
    }
    printf ("\n");
}

void fillIntArray (int** array, const int size)
{
    for (int i=0; i<size; ++i)
    {
        int value = rand() % 100;
        array[i]=value;
    }
}


void printIntArray (int* array, int size)
{
    for (int i=0; i<size; ++i)
    {
        printf ("[%d]", array[i]);
    }
    printf ("\n");
}

int get2dIntArray (int** array, const int row, const int col)
{
    return *((*(array+row))+col);
}

void set2dIntArray (int** array, const int row, const int col, int value)
{
    *((*(array+row))+col) = value;
}

int** init2dIntArray (int** array, const int row, const int col)
{
    array = (int**) calloc (sizeof(int*), row);
    for(int i=0; i<row; ++i)
    {
        *(array+i) = (int*) calloc (sizeof(int), col);
    }
    return array;
}

void fill2dIntArray (int** array, const int row, const int col)
{
    for (int i=0; i<row; ++i)
    {
        for(int j=0; j<col; ++j)
        {
            int value = rand() % 100;
            set2dIntArray (array, i, j, value);
        }
    }
}

void print2dIntArray (int** array, const int row, const int col)
{
    for (int i=0; i<row; ++i)
    {
        for (int j=0; j<col; ++j)
        {
            printf("[%d]", get2dIntArray(array, i, j));
        }
        printf ("\n");
    }
}



#endif // FUNCTIONS_H_INCLUDED
