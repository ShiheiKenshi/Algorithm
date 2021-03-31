#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

void sortInserts(int* array, int size)
{
    int temp, pos;
    for (int i=1; i<size; ++i)
    {
        temp = array[i];
        pos = i-1;
        while (pos >=0 && array[pos]> temp)
        {
            array[pos+1] = array[pos];
            pos--;
        }
        array[pos+1] = temp;
    }
}

void fastSort(int* array, int first, int last)
{
    int i = first, j = last;
    int median = isMedian(array, first, last);
    //printf("%d %d %d \n", first, last, median);

    do{
        while (array[i] < median) i++;
        while (array[j] > median) j--;

            if (i<=j)
            {
                swapInt(&array[i], &array[j]);
                i++;
                j--;
            }
       } while (i<=j);

    if (i<last)
        fastSort(array, i, last);
    if (first<j)
        fastSort(array, first, j);
}

int isMedian( int* array, int first, int last)
{
    int a=array[first], b=array[last], c=array[(first+last)/2];
   // printf("%d , %d , %d \n", a,b,c);

    if (a>b)
    {
        if (a>c)
            return (b>c) ? b : c;
        return a;
    }
    else
    {
        if (b<c)
            return b;
        return (a>c) ? a : c;
    }
}

void fastUpgrSort (int* array, int size)
{
    if (size<=10)
            sortInserts(array, size);
    fastSort(array, 0, size-1);
}

void bucketSort (int* array, int size)
{
const int max = size;
const int b = 10;
const int maxDigit=100000000;
int buckets[b][max+1];
for(int i=0; i<b; ++i)
{
    buckets[i][max] = 0;
}
for (int digit = 1; digit < maxDigit; digit*=10)
{
    for (int i=0; i<max; ++i)
    {
        if (array[i]%2==0)
        {

            int d = (array[i] / digit) % b;

            //int counter = buckets[d][max];
            //buckets[d][counter] = arr[i];
            //counter++;
            //bucket[d][max] = counter;

            buckets[d][buckets[d][max]++] = array[i];

            array[i] = -1;
        }
    }
    int idx = 0;
    for (int i=0; i<b; ++i)
    {
        for (int j=0; j<buckets[i][max]; ++j)
        {
            while (array[idx]!=-1)
                idx++;
            array[idx] = buckets[i][j];
        }
        buckets[i][max] = 0;
    }
}
}


int main (const int argc, const char **argv)
{
    int size = 12;
    int arr[size];
    fillIntArray(arr, size);
    printf("%s", "Initial array 12, fast sort: \n");
    printIntArray(arr, size);
    fastUpgrSort(arr, size);
    printIntArray (arr, size);
    printf("\n");

    int sizeA = 5;
    int arrA[sizeA];
    fillIntArray(arrA, sizeA);
    printf("%s", "Initial array 5, fast sort: \n");
    printIntArray(arrA, sizeA);
    fastUpgrSort(arrA, sizeA);
    printIntArray (arrA, sizeA);
    printf("\n");

    int sizeB = 37;
    int arrB[sizeB];
    fillIntArray(arrB, sizeB);
    printf("%s", "Initial array 37, fast sort: \n");
    printIntArray(arrB, sizeB);
    fastUpgrSort(arrB, sizeB);
    printIntArray (arrB, sizeB);
    printf("\n");

    int sizeC = 15;
    int arrC[sizeC];
    fillIntArray(arrC, sizeC);
    printf("%s", "Initial array 15, bucket sort: \n");
    printIntArray(arrC, sizeC);
    bucketSort(arrC, sizeC);
    printIntArray(arrC, sizeC);
    printf("\n");

    int sizeD = 30;
    int arrD[sizeD];
    fillIntArray(arrD, sizeD);
    printf("%s", "Initial array 30, bucket sort: \n");
    printIntArray(arrD, sizeD);
    bucketSort(arrD, sizeD);
    printIntArray(arrD, sizeD);
    printf("\n");


    return 0;
}
