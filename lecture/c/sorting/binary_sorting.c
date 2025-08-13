/*
    插入排序:
        - 直接插入排序
        - 折半排序 *
        - 希尔排序 
*/

#include <stdio.h>

typedef int ElemType;
void binary_sort(ElemType elems[], int c) {
    if (c < 2) {
        return;
    }
    int i, j, low, high, mid;
    for (i = 1; i < c; i++) {
        int temp = elems[i];
        low = 0;
        high = i-1;
        while(low <= high) { // 必须要等号，因为需要比较出h$igh指针所指的和temp
            mid = (low + high) / 2;
            if (elems[mid] > temp) high = mid - 1;
            else low = mid + 1;
        }
        for (j = i-1; j >= high+1; j--) {
            elems[j+1] = elems[j];
        }
        elems[high+1] = temp;
    }
}

int main(int argc, char** argv) {
    int elems[] = {3, 2, 5, 8, 3, 1, 3, 4};
    printf("before sorting elems\t = [\t");
    for (int i = 0; i < sizeof(elems)/sizeof(int); i++) {
        printf("%d\t", elems[i]);
    }
    printf("]\n");
    binary_sort(elems, sizeof(elems)/sizeof(int));
    printf("after sorting elems\t = [\t");
    for (int i = 0; i < sizeof(elems)/sizeof(int); i++) {
        printf("%d\t", elems[i]);
    }
    printf("]\n");
}