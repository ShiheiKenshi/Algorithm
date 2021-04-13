#ifndef LESSON_10_H_INCLUDED
#define LESSON_10_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define DEFAULT_STRING_LENGTH (32)

int simpleHashSum (char* in)
{
    int len = strlen(in);
    long int sum = 0;

    printf("For string %s: \n", in);

    for (int i = 0; i < len; ++i)
    {
        long int chr = (int)in[i];
        printf ("%c = %d \n", in[i], chr);
        sum = sum + chr;
    }

    printf("sum string %s = %d; \n \n", in, sum);
    return sum;
}

int* exchange (int* money, int size, int sum)
{
    printf("For sum %d you need: \n", sum);
    int coins[size];
    int tmp = sum;
    for (int i = 0; i < size; ++i)
    {
        int check = 0;
        while (tmp >= money[i])
        {
           tmp = tmp - money[i];
           check++;
        };
        coins[i] = check;
        printf("%d coin%s in denomination %d \n", check,(check>1) ? "s" : "", money[i]);
    }
    return *coins;
}

void printIntArray(int* array, int size, int offset) {
    char format[7];
    sprintf(format, "%%%dd", offset);
    for (int i = 0; i < size; ++i) {
        printf(format, array[i]);
        if (i != size - 1)
            printf(",");
    }
    printf("\n");
}


#endif // LESSON_10_H_INCLUDED
