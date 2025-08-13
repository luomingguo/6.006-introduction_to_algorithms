#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

typedef char vertex;

enum color {
    white = 1,
    gray,
    black
};

struct node {
    /* data */
    struct node *next;
    vertex key;             //
    enum color color;       //
    u_int32_t distance;     // dfs第一次计数值/或者是bfs的距离
    u_int32_t final_time;   // dfs第二次计数值
    int weight;             // 表示权重
    int is_header;          // 是否是头节点
    struct node* prev;      // 前驱节点
};

struct graph {
    /* data */
    struct node **headers;
    int num_vertexes;
};

struct graph *create_graph(int num_vertexes) {

    struct graph *graph = (struct graph *)malloc(sizeof(struct graph));
    assert(graph);
    graph->num_vertexes = num_vertexes;
    graph->headers = (struct node **) malloc(num_vertexes * sizeof(struct node*));
    assert(graph->headers);
    for (int i = 0; i < num_vertexes; ++i) {
        graph->headers[i] = (struct node *) malloc(sizeof(struct node));
        graph->headers[i]->color = white;
        graph->headers[i]->distance = 0;
        graph->headers[i]->next = NULL;
        graph->headers[i]->is_header = 0;
        graph->headers[i]->key = 'a' + i;
    }
    return graph;
}

void free_graph(struct graph *g) {
    if (!g) {
        return;
    }
    for (int i = 0; i < g->num_vertexes; i++) {
        if (!g->headers[i]) {
            continue;
        }
        free(g->headers[i]);
        g->headers[i] = NULL;
    }
    free(g->headers);
    free(g);
    g = NULL;
}

void add_edge(struct graph *g, vertex src, vertex dest) {
    add_edge_with_weight(g, src, dst, 0);
}

void add_edge_with_weight(struct graph *g, vertex src, vertex dest, int weight) {
    int src_index = src - 'a';
    int dest_index = dest - 'a';
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->key = dest;
    new_node->color = white;
    new_node->is_header = 0;
    new_node->next = g->headers[src_index]->next;
    new_node->weight = weight;
    g->headers[src_index]->next = new_node;

    // 如果是无向图，还需要添加从dest到src的边
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node->key = src;
    new_node->color = white;
    new_node->is_header = 0;
    new_node->weight = weight;
    new_node->next = g->headers[dest_index]->next;
    g->headers[dest_index]->next = new_node;
}

void print_graph(struct graph *g) {

    for (int i = 0; i < g->num_vertexes; ++i) {
        struct node *current_node = g->headers[i];
        printf("顶点 %c 的邻居列表：", i + 'a');
        while (current_node->next) {
            printf(" -> %c", current_node->next->key);
            current_node = current_node->next;
        }
        printf("\n");
    }
}

int (*weight)(struct graph* g, vertex src, vertex dst) {
    assert(g);
    int src_index = src - 'a';
    struct node *adj; // 邻接节点
    adj = g->headers[src_index]->next;
    while(adj) {
        if (adj->key == dst) {
            return adj->weight;
        }
        adj = adj->next;
    }
    return INT32_MIN;
}

