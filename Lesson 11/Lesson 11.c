#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Lesson 11.h"


int main (const int argc, const char **argv)
{
    int key = 3;
    char in[] = {"Mouse in the House~"};
    caesar(in, key, true);
    caesar(in, key, false);
    free(in);

    char in2[] = {""};
    caesar(in2, key, true);

    int keyCol = 5;
    char * inOne = "There one more function - shuffle";
    char * out = shuffle(inOne, keyCol, true);
    char * revers = shuffle(out, keyCol, false);
    return 0;
}
