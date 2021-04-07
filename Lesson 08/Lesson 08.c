#include "Lesson 08.h"

int main (const int argc, const char **argv)
{
    //question 8-1

    /*const int SZ = 12;
    int arr[SZ];
    fillRandIntArray(arr, SZ, 30);
    printf("%s", "Random array = ");
    printIntArray(arr, SZ, 3);
    BinTreeNode* tree = treeInsert(tree, arr[0]);
    fillTree(tree, arr, SZ);
    printf("%s", "Tree = ");
    printBinTree(tree);
    printf(" \n");

    tree = balancedTree(arr, SZ);
    printf("%s", "Balanced tree = ");
    printBinTree(tree);
    printf(" \n");
    printf("Checking tree for balance - %s \n", isBalanced(tree) ? "TRUE" : "FALSE");

    treeInsert(tree, 44);
    treeInsert(tree, 54);
    treeInsert(tree, 66);
    printf("%s", "Unbalanced tree = ");
    printBinTree(tree);
    printf(" \n");
    printf("Checking tree for balance - %s \n", isBalanced(tree) ? "TRUE" : "FALSE");
    clearIntArray(arr, SZ);

    BinTreeNode *treeTwo = NULL;
    printf("%s", "Empty Tree = ");
    printBinTree(treeTwo);
    printf(" \n");
    printf("Checking tree for balance - %s \n", isBalanced(treeTwo) ? "TRUE" : "FALSE");
*/
    //question 8-2
    const int SZTwo = 3;
    int arrTwo[SZTwo];
    int quantity = 10;
    BinTreeNode *arrTree[SZTwo];

    for (int i = 0; i < quantity; ++i)
    {
        fillRandIntArray(arrTwo, SZTwo, 30);
        printf("%s", "Random array = ");
        printIntArray(arrTwo, SZTwo, 3);
        printf("arrTwo[0]= %d \n", arrTwo[0]);
        arrTree[i] = treeInsert(arrTree[i], arrTwo[0]);
        printf("%s", "Multi Tree = ");
        fillTree(arrTree[i], arrTwo, SZTwo);
        printBinTree(arrTree[i]);
        printf("\n");
        clearIntArray (arrTwo, SZTwo);
    }
    printf("%s", "Multi Tree = ");
    printBinTree(arrTree[0]);
    printf(" \n");
    printf("%s", "Multi Tree = ");
    printBinTree(arrTree[2]);
    printf(" \n");


    //multiTreeCreation(3, 10);

    return 0;
}
