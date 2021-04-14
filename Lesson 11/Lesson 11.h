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

char* encryptionShuffle (char * in, int key, int len)
{
    char arr[7][key];
    int k = 0;
    while (k < len)
    {
        for(int i = 0, k = 0; i < len; ++i)
        {
            for(int j = 0; j < key; ++j)
            {
                arr[i][j] = in[k++];
            }
        }
    };

    char tmpOne [7][key];
    for (int i = 0; i < 7; ++i)
    {

        for (int j = 0; j < len/2; ++j)
        {
            tmpOne[i][j] = arr [i][j];
            arr[i][j] = arr[i][len-1-j];
        }
        for(int j = len - 1; j > len/2; --j)
        {
            arr[i][j] = tmpOne[i][len - 1 - j];
        }
    }
    k = 0;
    while (k < len)
    {
        for(int i = 0, k = 0; i < len; ++i)
        {
            for(int j = 0; j < key; ++j)
            {
                in[k++] = arr[i][j];
            }
        }
    };
}

char* decryptionShuffle (char * in, int key, int len)
{
    char arr[7][key];
    int k = 0;
    while (k < len)
    {
        for(int i = 0, k = 0; i < len; ++i)
        {
            for(int j = 0; j < key; ++j)
            {
                arr[i][j] = in[k++];
            }
        }
    };

    char tmpOne [7][key];
    for (int i = 0; i < 7; ++i)
    {

        for (int j = 0; j < len/2; ++j)
        {
            tmpOne[i][j] = arr [i][j];
            arr[i][j] = arr[i][len-1-j];
        }
        for(int j = len - 1; j > len/2; --j)
        {
            arr[i][j] = tmpOne[i][len - 1 - j];
        }
    }
    k = 0;
    while (k < len)
    {
        for(int i = 0, k = 0; i < len; ++i)
        {
            for(int j = 0; j < key; ++j)
            {
                in[k++] = arr[i][j];
            }
        }
    };
}

char* shuffle(char* in, int key, boolean encrypt)
{
    printf("String %s ", in);
    int len = strlen(in);
    if (encrypt == true)
    {
        encryptionShuffle(in, key, len);
    }
    else
    {
        decryptionShuffle(in, key, len);
    };
    printf("after %s became %s\n \n",
           (encrypt == true) ? "encryption" : "decryption" ,in);
    return *in;
}

#endif // LESSON_11_H_INCLUDED
