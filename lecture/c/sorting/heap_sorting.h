

typedef int elem_type;

typedef struct max_heap
{
    /* data */
    int length;
    int size;
    elem_type* data;
} max_heap, *p_max_heap;

inline int heap_size(p_max_heap p_heap);

void build_max_heap(p_max_heap p_heap);