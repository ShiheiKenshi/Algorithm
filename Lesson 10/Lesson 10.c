#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "Lesson 10.h"

int main (const int argc, const char **argv)
{
    //question 10-1
    char hashINone[] = {"House"};
    int sumOne = simpleHashSum(hashINone);
    char hashINtwo[] = {"~>_<~"};
    int sumTwo = simpleHashSum(hashINtwo);
    char hashINtree[] = {"{[++/*"};
    int sumTree = simpleHashSum(hashINtree);

    //question 10-2
    int money[] = {50, 10, 5, 2, 1};
    int size = 5;
    int sum = 399;
    int coins = exchange(money, size, sum);

    return 0;
}
