#include <stdio.h>
/*
    插入排序:
        - 直接插入排序
        - 折半排序
        - 希尔排序 * 
*/

typedef int ElemType;
void ShellSort(ElemType elems[], int c) { // c的数目不包括哨兵
    int dk, i, j;
    for (dk = c/2; dk >= 1; dk = dk / 2) {
        for (i = dk+1; i<=c; i++) {
            if (elems[i] < elems[i-dk]) {
                elems[0] = elems[i];
                for (j = i-dk; j>0 && elems[0]<elems[j]; j-=dk) {
                    elems[j+dk] = elems[j];
                }
                elems[j+dk] = elems[0];
            }
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
    ShellSort(elems, sizeof(elems)/sizeof(int));
#else
    ShellSort(elems, sizeof(elems)/sizeof(int)-1);
#endif    
    printf("after sorting elems\t = [\t");
    for (int i = 0; i < sizeof(elems)/sizeof(int); i++) {
        printf("%d\t", elems[i]);
    }
    printf("]\n");
}