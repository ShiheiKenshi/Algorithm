#ifndef LESSON_09_H_INCLUDED
#define LESSON_09_H_INCLUDED
#define T int
#define gSZ 7
#define true 1 == 1
#define false 1 != 1
typedef int boolean;

typedef struct Node
{
    T dat;
    struct Node *next;
} Node;

typedef struct
{
    Node *head;
    int size;
} Stack;

int visitedDepth[gSZ];

void initStack(Stack *stack)
{
    stack->head = NULL;
    stack->size = 0;
}

boolean push(Stack *stack, T value)
{
    Node *tmp = (Node*) malloc (sizeof(Node));
    if (tmp == NULL)
    {
        printf("Stack overflow \n");
        return false;
    }
    tmp->dat = value;
    tmp->next = stack->head;

    stack->head = tmp;
    stack->size++;
    return true;
}

T pop(Stack *stack)
{
    if (stack->size == 0)
    {
        //printf("Stack is empty \n");
        return -1;
    }
    Node *tmp = stack->head;
    T data = stack->head->dat;
    stack->head = stack->head->next;
    free(tmp);
    stack->size--;
    return data;
}

void printOneLinkIntNode(Node *n)
{
    if(n == NULL)
    {
        printf("[ ]");
        return;
    }
    printf("[%d]", n->dat);
}

void printOneLinkIntStack(Stack *stack)
{
    Node *current = stack->head;
    if(current == NULL)
    {
        printOneLinkIntNode(current);
    }
    else
    {
        do{
            printOneLinkIntNode(current);
            current = current->next;
        }
        while (current != NULL);
    }
    printf("Size: %d \n", stack->size);
}

void freeStack(Stack *stack)
{
    while(stack->size != 0)
        pop (stack);
    free(stack);
}

int** init2dIntArray(int** array, const int row, const int col)
{
    array = (int**) calloc(sizeof(int*), row);
    for (int i = 0; i < row; ++i) {
        *(array + i) = (int*) calloc(sizeof(int), col);
    }
    return array;
}

void set2dInt(int** array, const int row, const int col, int value)
{
    *((*(array + row)) + col) = value;
}

void resetMatrix (int **matrix)
{
    for (int i = 0; i < gSZ; ++i)
        {
            for (int j = 0; j < gSZ; ++j)
            {
                matrix[i][j] = 0;
            }
        }
}

void resetArray(int *array)
{
    for (int i = 0; i < gSZ; ++i)
    {
        array[i] = 0;
    }
}

/*  1  2  3  4  5  6  7
   {0, 1, 1, 0, 0, 0, 0} 1
   {1, 0, 1, 1, 0, 0, 0} 2
   {1, 1, 0, 1, 1, 0, 0} 3
   {0, 1, 1, 0, 0, 0, 0} 4
   {0, 0, 1, 0, 0, 0, 0} 5
   {0, 0, 0, 0, 0, 0, 1} 6
   {0, 0, 0, 0, 0, 1, 0} 7 */

int** createGraph ()
{
        int** matrix = init2dIntArray(matrix, gSZ, gSZ);
        resetMatrix(matrix);
        set2dInt(matrix, 0, 1, 1);
        set2dInt(matrix, 0, 2, 1);
        set2dInt(matrix, 1, 0, 1);
        set2dInt(matrix, 1, 2, 1);
        set2dInt(matrix, 1, 3, 1);
        set2dInt(matrix, 2, 0, 1);
        set2dInt(matrix, 2, 1, 1);
        set2dInt(matrix, 2, 3, 1);
        set2dInt(matrix, 2, 4, 1);
        set2dInt(matrix, 3, 1, 1);
        set2dInt(matrix, 3, 2, 1);
        set2dInt(matrix, 4, 2, 1);
        set2dInt(matrix, 5, 6, 1);
        set2dInt(matrix, 6, 5, 1);

        return matrix;
}

void depthTraversStack (int** matrix, int start)
{
    printf("%s", "Visited nodes: ");
    printf("%d ", start);
    depthTravers(matrix, start);
    printf("\n");
    resetArray(visitedDepth);
}

void depthTravers (int** matrix, int start)
{
    visitedDepth[start] = 1;
    Stack* stack = (Stack*) malloc (sizeof(Stack));
    initStack(stack);
    push (stack, start);
    while (stack->size != 0)
    {
        for (int r = 0; r < gSZ; ++r)
        {
            if (matrix [start][r] == 1 && !visitedDepth[r])
            {
                push(stack, r);
                visitedDepth[r] = 1;
                printf("%d ", r);
                depthTravers(matrix, r);
            }
            else
            {
                pop(stack);
            }
        }
    }
    freeStack(stack);
}

int link[gSZ] = {0};

void adjacencyCount (int** matrix, const int size)
{
    for (int i = 0; i < size; ++i)
        {
            for (int j = 0; j < size; ++j)
                {
                    if (matrix[j][i] == 1 && i != j)
                        link[i]++;
                }
                printf("For %d adjacency link = %d \n", i, link[i]);
        }
    resetArray(link);
}

int count[gSZ] = {0};

void traversalCount(int** matrix, int start, const int size)
{
    for (int s = 0; s < gSZ; ++s)
    {
        if (matrix[start][s] == 1 && start != s)
            link[start]++;
    }
    printf("For %d adjacency link = %d \n", start, link[start]);
    count[start] = 1;

    for (int v = 0; v <gSZ; ++v)
    {
        if (matrix[start][v] == 1 && count != 1)
        {
            count[v] = 1;
            for (int i = 0; i < size; ++i)
            {
                for (int j = 0; j < size; ++j)
                    {
                        if (matrix[j][i] == 1 && i != j)
                            link[i]++;
                    }
            }
            printf("For %d adjacency link = %d \n", v, link[v]);
        }
    }
    resetArray(link);
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

#endif // LESSON_09_H_INCLUDED
