#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct queue_node {
    char data;
} queue_node;


struct queue
{
    int head;
    int tail;
    queue_node **list;
    int cnt; // 节点个数；最大队列长度是cnt-1
};

struct queue* create_queue(int capacity) {
    
    if (capacity < 1) {
        return NULL;
    }
    
    struct queue* queue = (struct queue*)malloc(sizeof(struct queue));
    assert(queue);
    queue->cnt = capacity+1;
    queue->list = (struct queue_node**)malloc(queue->cnt * sizeof(struct queue_node*));
    assert(queue->list);
    for (int i = 0; i < queue->cnt; i++) {
        queue->list[i] = (struct queue_node*) malloc(sizeof(struct queue_node));
    }
    queue->head = 0;
    queue->tail = 0;
    
    return queue;
}

void free_queue(struct queue* q) {
    if (!q || !q->list) {
        return;
    }
    for (int i = 0; i < q->cnt; i++) {
        free(q->list[i]);
    }
    free(q->list);
    q->list = NULL;
    free(q);
    q = NULL;
}

int empty_queue(struct queue* q) {
    assert(q);
    return q->head == q->tail;
}

int full_queue(struct queue* q) {
    assert(q);
    return (q->tail + 1) % q->cnt == q->head;
}

int enqueue(struct queue *q, char data) {
    if (full_queue(q)) {
        // perror("queue is full already.\n");
        return -1;
    }
    q->list[q->tail]->data = data;
    q->tail = (q->tail + 1) % q->cnt;

    return 0;
}

int dequeue(struct queue* q, char* data) {
    char* in = (char*) data;
    if (empty_queue(q)) {
        perror("queue is empty already.\n");
        return -1;
    }
    // 使用strncpy来复制数据，并确保不会越界
    *data = q->list[q->head]->data;
    q->head = (q->head + 1) % q->cnt;
    return 0;
}

