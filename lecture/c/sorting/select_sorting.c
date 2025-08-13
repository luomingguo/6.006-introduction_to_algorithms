/*
    选择排序
        简单选择排序*
        堆排序
*/

#include <stdio.h>
#include <stdint.h>

typedef int ElemType;
void select_sort(ElemType elems[], int c) {
    int min_idx;
    ElemType min_val;

    int i, j;
    if (c < 2) {
        return;
    }
    for (i = 0; i < c-1; i++) {
        min_idx = i;
        for (j = i+1; j < c; j++) {
            if (elems[min_idx] > elems[j]){
                min_idx = j;
            }
        }
        if (min_idx != i) {
            int tmp = elems[i];
            elems[i] = elems[min_idx];
            elems[min_idx] = tmp;
        }
    }
}

int main(int argc, char** argv) {
#ifdef SENTINELS
    int elems[] = {0, 3, 2, 5, 8, 3, 1, 3};
#else
    int elems[] = {3, 2, 5, 8, 3, 1, 3};
#endif
    printf("before sorting elems\t = [\t");
    for (int i = 0; i < sizeof(elems)/sizeof(int); i++) {
        printf("%d\t", elems[i]);
    }
    printf("]\n");
#ifdef SENTINELS
    SelectSort(elems, sizeof(elems)/sizeof(int)-1);
#else
    select_sort(elems, sizeof(elems)/sizeof(int));
#endif    
    printf("after sorting elems\t = [\t");
    for (int i = 0; i < sizeof(elems)/sizeof(int); i++) {
        printf("%d\t", elems[i]);
    }
    printf("]\n");
}