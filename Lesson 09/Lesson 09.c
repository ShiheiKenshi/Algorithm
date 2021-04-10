#include <stdio.h>
#include "Lesson 09.h"

int main (const int argc, const char **argv)
{
    // 9-1
    printf("Question 1 \n");
    int** graph = createGraph();
    depthTraversStack(graph, 4);
    depthTraversStack(graph, 0);
    depthTraversStack(graph, 5);

    //9-2
    printf("Question 2a \n");
    adjacencyCount(graph, gSZ);
    printf("Question 2b \n");
    traversalCount(graph, 0, gSZ);
    printf("\n");
    traversalCount(graph, 2, gSZ);
    printf("\n");
    traversalCount(graph, 5, gSZ);

    return 0;
}
