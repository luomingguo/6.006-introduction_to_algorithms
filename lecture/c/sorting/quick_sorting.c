/*
    交换排序
        冒泡排序
        快速排序*
*/

#include <stdio.h>
#include <stdint.h>
#include <memory.h>
#include <stdlib.h>

typedef int ElemType;

int partition(ElemType elems[], int lft, int rgt) {
    int x = elems[rgt];
    int i = lft - 1;
    int j = lft;
    ElemType tmp;
    while (j < rgt) {
        if (elems[j] < x) {
            i++;
            tmp = elems[j];
            elems[j] = elems[i];
            elems[i] = tmp;
        }
        j++;
    }
    tmp = elems[rgt];
    elems[rgt] = elems[i+1];
    elems[i+1] = tmp;
    return i+1;
}

void quick_sort(ElemType *elems, int lft, int rgt) {
    if (lft < rgt) {
        int mid = partition(elems, lft, rgt);
        quick_sort(elems, lft, mid-1);
        quick_sort(elems, mid+1, rgt);
    }
}

int main(int argc, char** argv) {

    ElemType elems[] = {3, 2, 5, 8, 3, 1, 3};
    printf("before quick_sort elems\t = [\t");
    for (int i = 0; i < sizeof(elems)/sizeof(int); i++) {
        printf("%d\t", elems[i]);
    }
    printf("]\n");
    quick_sort(elems, 0, sizeof(elems)/sizeof(int)-1);
    printf("after quick_sort elems\t = [\t");
    for (int i = 0; i < sizeof(elems)/sizeof(int); i++) {
        printf("%d\t", elems[i]);
    }
    printf("]\n");
}