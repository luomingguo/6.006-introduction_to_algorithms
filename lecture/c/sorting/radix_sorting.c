/*
    description: 基数排序
*/

#include <stdio.h>
#include <stdint.h>
#include <memory.h>
#include <stdlib.h>

typedef int ElemType;

void radix_sort(ElemType elems[]) {


}

int main(int argc, char** argv) {

    ElemType elems[] = {3, 2, 5, 8, 3, 1, 3};
    printf("before radix_sort elems\t = [\t");
    for (int i = 0; i < sizeof(elems)/sizeof(int); i++) {
        printf("%d\t", elems[i]);
    }
    printf("]\n");
    MergeSort(elems, 0, sizeof(elems)/sizeof(int)-1);
    printf("after radix_sort elems\t = [\t");
    for (int i = 0; i < sizeof(elems)/sizeof(int); i++) {
        printf("%d\t", elems[i]);
    }
    printf("]\n");
}