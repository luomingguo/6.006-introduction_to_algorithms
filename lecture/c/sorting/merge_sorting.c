#include <stdio.h>
#include <stdint.h>
#include <memory.h>
#include <stdlib.h>

#define SENTINELS
typedef int ElemType;

// 有哨兵
void Merge(ElemType elems[], int p, int q, int r) {
    int n1 = q-p+1;
    int n2 = r-q;
    ElemType *left = (ElemType*) malloc((n1 + 1) * sizeof(ElemType));
    ElemType *right = (ElemType*) malloc((n2 + 1) * sizeof(ElemType));
    memcpy(left, (void*)&elems[p], n1 * sizeof(ElemType));
    left[n1] = INT32_MAX;
    memcpy(right, (void*)&elems[q+1], n2 * sizeof(ElemType));
    right[n2] = INT32_MAX;
    int i = 0;  
    int j = 0;
    for (int k = p; k < r + 1; k++) {
        if (left[i] <= right[j]) {  
            elems[k] = left[i];
            i++;
        } else {
            elems[k] = right[j];
            j++;
        }
    }
    free(left);
    free(right);
}


// 无哨兵
void merge(ElemType elems[], int p, int q, int r) {
    int n1 = q-p+1;
    int n2 = r-q;
    ElemType *left = (ElemType*) malloc(n1 * sizeof(ElemType));
    ElemType *right = (ElemType*) malloc(n2 * sizeof(ElemType));
    memcpy(left, (void*)&elems[p], n1 * sizeof(ElemType));
    memcpy(right, (void*)&elems[q+1], n2 * sizeof(ElemType));
    int i = 0;  
    int j = 0;
    for (int k = p; k < r + 1; k++) {
        if (i == n1) {
            elems[k] = right[j];
            j++;
        }
        else if (j == n2) {
            elems[k] = left[i];
            i++;
        }
        else if (left[i] <= right[j]) {  
            elems[k] = left[i];
            i++;
        } else {
            elems[k] = right[j];
            j++;
        }
    }
    free(left);
    free(right);
    return;
}

// 有哨兵
void MergeSort(ElemType elems[], int p, int r) {
#ifdef SENTINELS
    if (p < r) {  
        int q = (p + r) / 2; // 如果是相邻的话必然p == r 在下一个阶段就退出了
        MergeSort(elems, p, q);
        MergeSort(elems, q+1, r);
        Merge(elems, p, q, r);
    }
#else
    if (p < r) {
        int q = (p + r) / 2;
        MergeSort(elems, p, q);
        MergeSort(elems, q+1, r);
        merge(elems, p, q, r);
    }
#endif
}

int main(int argc, char** argv) {

    ElemType elems[] = {3, 2, 5, 8, 3, 1, 3};
    printf("before sorting elems\t = [\t");
    for (int i = 0; i < sizeof(elems)/sizeof(int); i++) {
        printf("%d\t", elems[i]);
    }
    printf("]\n");
    MergeSort(elems, 0, sizeof(elems)/sizeof(int)-1);
    printf("after sorting elems\t = [\t");
    for (int i = 0; i < sizeof(elems)/sizeof(int); i++) {
        printf("%d\t", elems[i]);
    }
    printf("]\n");
}