/*
    选择排序
        简单选择排序
        堆排序  *
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "heap_sorting.h"

int parent(int idx) {
    return idx/2;
}

int left(int idx) {
    return 2 * idx + 1;
}

int right(int idx) {
    return 2 * idx + 2;
}

int heap_size(p_max_heap p_heap) {
    if (!p_heap) {
        return 0;
    }
    return p_heap->size;
}

// 将p_heap[left], p_heap[right], p_heap[idx]选出最大的，并保存在largest中
void max_heapify(p_max_heap p_heap, int idx) {
    int lf_idx = left(idx);
    int ri_idx = right(idx);
    int largest = idx;
    if (lf_idx < heap_size(p_heap) && p_heap->data[lf_idx] > p_heap->data[largest]) {
        largest = lf_idx;
    } else {
        largest = idx;
    }
    if (ri_idx < heap_size(p_heap) && p_heap->data[ri_idx] > p_heap->data[largest]) {
        largest = ri_idx;
    }
    if (largest != idx) {
        elem_type temp = p_heap->data[largest];
        p_heap->data[largest] = p_heap->data[idx];
        p_heap->data[idx] = temp;
        max_heapify(p_heap, largest);
    }
    return;
}

void build_max_heap(p_max_heap p_heap) {
    p_heap->size = p_heap->length;
    for (int i = p_heap->length / 2; i >= 0; i--) {
        max_heapify(p_heap, i);
    } 
}

void heap_sort(p_max_heap p_heap) {
    build_max_heap(p_heap);
    for (int i = p_heap->length-1; i > 0; i--) {
        elem_type temp = p_heap->data[0];
        p_heap->data[0] = p_heap->data[i];
        p_heap->data[i] = temp;
        p_heap->size--;
        max_heapify(p_heap, 0);
    }
}

int main(int argc, char** argv) {
    elem_type elems[] = {3, 2, 5,9,4,5, 8, 3, 1, 3};

    printf("before sorting elems\t = [\t");
    for (int i = 0; i < sizeof(elems)/sizeof(elem_type); i++) {
        printf("%d\t", elems[i]);
    }
    printf("]\n");
    max_heap max_heap_instance = {
        .length = sizeof(elems)/sizeof(elem_type),
        .size = sizeof(elems)/sizeof(elem_type),
        .data = (elem_type*)malloc(sizeof(elems)),
    };
    memset(max_heap_instance.data, 0, sizeof(elems));
    memcpy(max_heap_instance.data, elems, sizeof(elems));
    heap_sort(&max_heap_instance);
    memcpy(elems, max_heap_instance.data, sizeof(elems));
    free(max_heap_instance.data);
    printf("after sorting elems\t = [\t");
    for (int i = 0; i < sizeof(elems)/sizeof(elem_type); i++) {
        printf("%d\t", elems[i]);
    }
    printf("]\n");
}
