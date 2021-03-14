#include <stdio.h>

int check(long p)
{
    while (p<=0)
    {
        printf("%s \n", "Number must be greater than 0: ");
        scanf("%d \n", &p);
    }
    return 1;
}

int checkprime(long p)
{
    int c = 0;
    if (p<=3)
    {
        printf ("%s \n", "This is prime number.");
    }
    else
    {
        for (int i=2; i<=p/2; i++)
        {
            if(p%i == 0)
            {
                c = 1;
            }
        }
            if (c)
            {
                printf ("%s \n", "This is'nt prime number.");
            }
            else
            {
                printf ("%s \n", "This is prime number.");
            }

    }
}

int main (int argc, const char ** argv)
{

    long p;
    printf("%s \n", "Enter positive number: ");
    scanf("%d", &p);
    check(p);
    checkprime(p);

}
