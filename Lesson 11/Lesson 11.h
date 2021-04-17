#ifndef LESSON_11_H_INCLUDED
#define LESSON_11_H_INCLUDED
#include <string.h>
#include <math.h>
#define true 1 == 1
#define false 1 != 1
typedef int boolean;

char* encryption(char* in, int key, int len)
{
    for (int i = 0; i < len; ++i)
    {
        in[i] = in[i]+key;
    }
    return in;
}

char* decryption (char * in, int key, int len)
{
    for (int i = 0; i < len; ++i)
    {
        in[i] = in[i]-key;
    }
    return in;
}

char* caesar(char* in, int key, boolean encrypt)
{
    printf("String %s ", in);
    int len = strlen(in);
    if (in == NULL || len == 0)
    {
        printf ("is empty. \n \n");
        return NULL;
    }
    if (encrypt == true)
    {
        encryption(in, key, len);
    }
    else
    {
        decryption(in, key, len);
    };
    printf("after %s became %s\n \n",
           (encrypt == true) ? "encryption" : "decryption" ,in);
    return *in;
}

char* shuffle(char* in, int key, boolean encrypt)
{
    printf("String %s ", in);
    int len = strlen(in);
    if (in == NULL || len == 0)
    {
        return NULL;
    }
    int strng = ceil((float)len/(float)key);
    int length = key * strng;
    char * out = (char*)calloc (length+1, sizeof(char));
    if (encrypt == false)
    {
        key = strng;
    }
    int k = 0;
    for (int i = 0; i < key; ++i)
    {
        for (int j = i; j < length; j+=key)
        {
            if (j < len)
            {
                out[k] = in[j];
            }
            else
            {
                out[k] = ' ';
            }
            k++;
        }
    }
    printf("after %s became %s\n \n",
           (encrypt == true) ? "encryption" : "decryption" , out);
    return out;
}

#endif // LESSON_11_H_INCLUDED
