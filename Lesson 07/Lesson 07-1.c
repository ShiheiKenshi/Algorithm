#include <stdio.h>
#include <stdlib.h>

#include "function 7 lesson.h"

int main()
{
    braces_succession_checker();

    List *lst1 = (List*)malloc(sizeof(List));
    init(lst1);
    printList(lst1);
    List *lst2 = (List*)malloc(sizeof(List));
    init(lst2);
    printList(lst2);
    for (int i=1; i<=10; ++i)
    {
        ins(lst1, i);
    }
    printf("List 1: ");
    printList(lst1);
    copyList(lst1, lst2);
    printf("List 2: ");
    printList(lst2);
    printf("List 1 don't have changes: "); printList(lst1);

    List *SortList = (List*)malloc(sizeof(List));
    init(SortList);
    for(int i=1; i<6; ++i)
    {
        ins(SortList, i);
    }
    printList(SortList);
    printf("List is sorted - %s \n", lstSorted(SortList) ? "TRUE" : "FALSE");

    for(int i=1; i<6; ++i)
    {
        rm(SortList, i);
    }
    printf("List is cleared :"); printList(SortList);

    for(int i=5; i>0; --i)
    {
        ins(SortList, i);
    }
    printList(SortList);
    printf("List is sorted - %s \n", lstSorted(SortList) ? "TRUE" : "FALSE");
    for(int i=5; i>0; --i)
    {
        rm(SortList, i);
    }
    printf("List is cleared :"); printList(SortList);

    for(int i=1; i<6; ++i)
    {
        ins(SortList, i);
    }
    ins(SortList, 1);
    printList(SortList);
    printf("List is sorted - %s \n", lstSorted(SortList) ? "TRUE" : "FALSE");

    return 0;
}
