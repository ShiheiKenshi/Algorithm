#include <stdio.h>

void dec_to_bin(unsigned int n)
{
    if ( n / 2 )
        dec_to_bin(n / 2);

    printf("%d", n % 2);
}

void decim_to_binar(void)
{
  printf("%s", "Enter decimal number: ");
  unsigned int n;
  scanf("%d", &n);
  dec_to_bin(n);
}

int expon(int a, int b)
{
    if(b==1)
    {
        return a;
    }
    else
    {
        return a*expon(a,(b-1));
    }
}
void exponent(void)
{
 int a, b;
 printf("%s", "Enter number: ");
 scanf("%d", &a);
 printf("%s", "Enter exponent: ");
 scanf("%d", &b);
 printf("%d", expon(a, b));
}

int binpow(int a, int b)
{
    if (b==0)
    {
       return 1;
    }
    if (b%2==1)
    {
       return binpow(a,(b-1))*a;
    }
    else
    {
        int c = binpow(a, b/2);
        return (c * c);
    }
}

void binarypow(void)
{
    int a, b;
 printf("%s", "Enter number: ");
 scanf("%d", &a);
 printf("%s", "Enter exponent: ");
 scanf("%d", &b);
 printf("%d", binpow(a, b));
}

int chess(void)
{
    int  a, b;
    int board[8][8] = {{0,0,0,0,0,0,0,0},
                      {0,0,0,0,0,1,1,1},
                      {0,0,1,1,1,0,0,0},
                      {0,0,0,0,0,0,0,0},
                      {0,0,0,0,1,1,1,0},
                      {0,0,0,0,0,0,0,0},
                      {0,1,1,1,0,0,0,0},
                      {0,0,0,0,0,0,0,0}};
    for(int i=0; i<8; i++) // output board
    {
        for(int j=0; j<8; j++)
        {
            printf("%3d", board[i][j]);
        }
        printf("\n");
    }
    printf("%s \n", "Enter row and collum for King piece: ");
    scanf("%d", &a);
    scanf("%d", &b);
    while(board[a-1][b-1]==1)
    {
        printf("%s \n", "This place already has piece. Enter new row and collum.");
        scanf("%d",&a);
        scanf("%d",&b);
    };
    board[a-1][b-1] = 2;
        for(int i=0; i<8; i++) // output board
    {
        for(int j=0; j<8; j++)
        {
            printf("%3d", board[i][j]);

        }
        printf("\n");
    }
    int c, d, e, f;
    c = check_min(a);
    d = check_max (a);
    e = check_min (b);
    f = check_max (b);
    for(int i = (c-1); i<=(d-1); i++)
    {
        for(int j=(e-1); j<=(f-1); j++)
        {
            if(board[i][j]==0)
            {
                printf("King can move to %d %d \n", i+1, j+1);
            }
        }
    }
}

int check_min (int a)
{
    if ((a-1)>0)
    {
        return (a-1);
    }
    else
    {
        return a;
    }
}

int check_max(int a)
{
    if((a+1)<9)
    {
        return (a+1);
    }
    else
    {
        return a;
    }
}

int main(void)
{
    unsigned int N=0;
    printf("%s", "Choose number of question: \n");
    printf("%s", "1. Convert decimal to binary. \n");
    printf("%s", "2. Exponentiation. \n");
    printf("%s", "3. Binary exponentiation. \n");
    printf("%s", "4. Chess. \n");

    scanf("%u", &N);

    switch(N)
    {
    case 1:
       decim_to_binar();
       break;
    case 2:
        exponent();
        break;
    case 3:
        binarypow();
        break;
    case 4:
        chess();
        break;
    default:
        printf("error \n");
        break;
    }
    return 0;
}
