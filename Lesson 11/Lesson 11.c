#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Lesson 11.h"


int main (const int argc, const char **argv)
{
    int key = 3;
    char in[] = {"Mouse in the House"};
    caesar(in, key, true);
    caesar(in, key, false);

    int keyCol = 5;
    char inOne[] = {"There one more function - shuflle"};
    shuffle(inOne, keyCol, true);
    shuffle(inOne, keyCol, false);
    return 0;
}
