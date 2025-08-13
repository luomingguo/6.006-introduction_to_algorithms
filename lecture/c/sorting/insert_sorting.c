/*
    插入排序:
        - 直接插入排序 *
        - 折半排序
        - 希尔排序 
*/
#include <stdio.h>

typedef int ElemType;
#define SENTINELS 1
void insert_sort(int elems[], int c) {

    if (c < 2) {
        return;
    }
    int sorted_index = 0;
    for (int i = 1; i < c; i++) {
        int temp = elems[i];
        sorted_index = i - 1;
        while (temp < elems[sorted_index] && sorted_index >= 0) {
            elems[sorted_index+1] = elems[sorted_index];
            sorted_index--;
        }
        elems[sorted_index+1] = temp;
    }
}

// 哨兵模式，从下标为1开始计算
void 
InsertSort(ElemType A[], int n) { // n数目加上了哨兵
    int i, j;
    for (i = 2; i <= n; i++) { //排序A[2]~A[n]
        if (A[i] < A[i-1]) {
            A[0] = A[i];
            for (j = i-1; A[0] < A[j]; j--){
                A[j+1] = A[j];
            }
            A[j+1] = A[0];
        }
    }
}

int main(int argc, char** argv) {

#ifdef SENTINELS
    int elems[] = {3, 2, 5, 8, 3, 1, 3};
#else
    int elems[] = {0, 3, 2, 5, 8, 3, 1, 3};
#endif
    printf("before sorting elems\t = [\t");
    for (int i = 0; i < sizeof(elems)/sizeof(int); i++) {
        printf("%d\t", elems[i]);
    }
    printf("]\n");
#ifdef SENTINELS
    insert_sort(elems, sizeof(elems)/sizeof(int));
#else
    InsertSort(elems, sizeof(elems)/sizeof(int)-1);
#endif
    printf("after sorting elems\t = [\t");
    for (int i = 0; i < sizeof(elems)/sizeof(int); i++) {
        printf("%d\t", elems[i]);
    }
    printf("]\n");
}