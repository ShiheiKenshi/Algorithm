#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "functions.h"

void Simp2dArray (int** array, int* array2, const int row, const int col, const int length)
{
    int a=0;
    for (int i=0; i<row; ++i)
    {
        for (int j=0; j<col; ++j)
        {
            array2[a++] = get2dIntArray(array, i, j);

        }
    }
}

void bubbleSort (int* array, int len)
{
    for (int i=0; i<len; ++i)
    {
        for (int j=0; j<len-1; ++j)
        {
            if (array[j]>array[j+1])
                swapInt(&array[j], &array[j+1]);
        }
    }
}

void ChangeTo2dArray (int** array, int* array2, const int row, const int col, const int length)
{
    int s=0;
    for (int i=0; i<row; ++i)
    {
        for (int j=0; j<col; ++j)
        {
            int value = array2[s++];
            set2dIntArray(array, i, j, value);
        }
    }
}

void reverseDblArray(double* a, double *b, int len)
{
    for (int i=0; i< len; ++i)
    {
        b[i] = a[len-(i+1)];
    }
}

void functionTPK (double* b, int len)
{
    int y=400;
    for (int i=0; i<len; ++i)
    {
        double x=b[i];
        b[i]=sqrt(fabs(x))+5*pow(x,3);
        if (b[i]>y)
        {
            printf("Number %lf after calculation is equal to %lf and exceeds 400 \n", x, b[i]);
        }
        /*else
        {
            printf("Number %lf after calculation is equal to %lf \n", x,b[i]);
        }*/
    }
}

void question_a(int row, int col)
{
    const int ROW = row, COL = col;
    int** arr = init2dIntArray(arr, ROW, COL);
    fill2dIntArray (arr, ROW, COL);
    printf("%s", "Random 2D array: \n");
    print2dIntArray (arr, ROW, COL);

    int len = ROW*COL;
    int arr2[len];
    Simp2dArray (arr, arr2, ROW, COL, len);
    printf("%s","From 2D to 1D array: \n");
    printIntArray (arr2, len);

    bubbleSort(arr2, len);
    printf("%s","1D array after bublle sorting: \n");
    printIntArray(arr2, len);

    ChangeTo2dArray(arr, arr2, ROW, COL, len);
    printf("%s","Random 2D array after bublle sorting: \n");
    print2dIntArray(arr, ROW, COL);
    free(arr);
}

void question_b(double* a, int len)
{
    /*printf("%s", "Enter 11 numbers: ");
    for (int i=0; i< len; ++i)
    {
        scanf("%lf", &a[i]);
    }*/
    printf("%s", "Created array: \n");
    printDblArray(a,len);
    double b[len];
    reverseDblArray(a,b,len);
    printf("%s", "Reversed array: \n");
    printDblArray(b,len);
    functionTPK(b, len);

}

int main (const int argc, const char **argv)
{
    question_a(3, 3);
    printf("\n");
    question_a(5,4);
    printf("\n");
    question_a(2,4);
    printf("\n");
    int len =11;
    double a[11] = {3.67, -96.75, 67.84, 71.24, -27.87, -20.84, -57.46, 15.23, -95.88, 9.53, -15.14};
    question_b(a, len);
    printf("\n");
    double b[11] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    question_b(b, len);
    printf("\n");
    double c[11] = {1, 1.1, 1.2, 1.3, 1.4, 1.5, 1.6, 1.7, 1.8, 1.9, 1.10};
    question_b(c, len);



    return 0;
}
