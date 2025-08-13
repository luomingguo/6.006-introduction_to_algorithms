#include <assert.h>

typedef struct stack_node {
    void *data;
} stack_node;

struct stack
{
    /* data */
    int top;
    int capacity;
    stack_node **list;
};

stack* create_strack(int capacity) {
    if (capacity < 1) {
        return NULL;
    }

    stack* stack = (stack*) malloc(sizeof(stack));
    assert(stack);
    if (stack == NULL) {
        free(q);
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
}