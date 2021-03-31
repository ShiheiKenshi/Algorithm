#include<stdio.h>
#define SZ 10
#define S int
#define true 1 == 1
#define false 1 != 1

int cursor = -1;
S Stack[SZ];
typedef int boolean;

boolean push(S data)
{
    if (cursor < SZ)
    {
        Stack[++cursor] = data;
        return true;
    }
    else
    {
        printf("%s \n", "Stack overflow");
        return false;
    }
}

int DecToBin (int num)
{
    return num < 2 ? num % 2 : (num%2) + 10 * DecToBin(num/2);
}

S pop(void)
{
    if(cursor != -1)
    {
        int num = Stack[cursor--];
        return DecToBin(num);
    }
    else
    {
        printf("%s \n", "Stack is empty");
        return -1;
    }
}

typedef struct
{
    int pr;
    int dat;
} Node;

Node* arr[SZ];
int head;
int tail;
int items;

void swap (int *a, int i, int j)
{
    int tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}

void init(void)
{
    for (int i=0; i<SZ; ++i)
    {
        arr[i] = NULL;
    }
    head = 0;
    tail = 0;
    items = 0;
}

void ins(int pr, int dat)
{
    Node *node = (Node*) malloc (sizeof(Node));
    node->dat = dat;
    node->pr = pr;
    int flag;

    if(items==0)
    {
        arr[tail++] = node;
        items++;
    }
    else if(items != SZ)
    {
        int i = 0;
        int idx = 0;
        Node * tmp;
        for (i = head; i < tail; ++i)
        {
            idx = i%SZ;
            idx++;
        }
        flag = idx % SZ;
        i++;
        while (i <= tail)
        {
            idx = i % SZ;
            tmp = arr[idx];
            arr[idx] = arr[flag];
            arr[flag] = tmp;
            i++;
        }
        arr[flag] = node;
        items++;
        tail++;
    }
    else
    {
        printf("%s", "Queue is full \n");
        return;
    }
}

Node* rem(void)
{
    if (items == 0)
    {
        return NULL;
    }
    else
    {
        int i = 0;
        int idx = 0;
        int pr = 0;
        Node * tmp;
        for (i = head; i < tail; ++i) //search max pr
        {
            idx = i%SZ;
            if (arr[idx]->pr > pr)
            {
               pr = arr[idx]->pr;
               tmp = arr[idx];
            }
        }
        for (i = head; i<tail; ++i) //clear node with max pr
        {
            idx = i%SZ;
            if (arr[idx] == tmp)
            {
                arr[idx] = NULL;
            }
        }
        int j;
        for (i = head, j = head; j< tail; ++j) // shift array
        {
            if (arr[j] !=0)
            {
                if (i<j)
                {
                    swap(arr, i, j);
                }
                i++;
            }
        }
        items--;
        tail--;
        //printf("head= %d,tail= %d,items= %d \n", head, tail, items);
        return tmp;
    }
}

void printQueue(void)
{
    printf("[");
    for (int i=0; i<SZ; ++i)
    {
        if (arr[i] == NULL)
            printf("[*, *] ");
        else
        printf("[%d, %d] ", arr[i]->pr, arr[i]->dat);
    }
    printf(" ]\n");
}

int main (const int argc, const char **argv)
{
    init();
    ins(1,11);
    ins(3,22);
    ins(5,33);
    ins(7,44);
    ins(5,55);
    ins(2,66);
    ins(4,77);
    ins(3,88);
    ins(5,99);
    ins(2,100);
    //ins(1,101);
    printQueue();
    for (int i = 0; i < 7; ++i)
    {
        Node* n = rem();
        printf("pr=%d, dat=%d \n", n->pr, n->dat);
    }
    printQueue();

    ins(1, 110);
    ins(3, 120);
    ins(6, 130);
    printQueue();

    for (int i = 0; i < 3; ++i)
    {
        Node* n = rem();
        printf("pr=%d, dat=%d \n", n->pr, n->dat);
    }
    printQueue();

    push(5);
    push(6);
    push(7);
    push(11);
    push(12);
    push(13);
    push(21);
    push(2);
    while (cursor != -1)
    {
        printf("%d \n", pop());
    }


    return 0;
}
