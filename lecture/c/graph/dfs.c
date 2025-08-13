#include <stdio.h>
#include <assert.h>

#include "graph.h"


void dfs_visit(struct graph* g, vertex v, int* time) {
    assert(g);
    (*time)++;
    int idx = v - 'a';
    int next_idx;
    g->headers[idx]->distance = (*time);
    g->headers[idx]->color = gray;
    printf("-> %c", g->headers[idx]->key);
    struct node* next = g->headers[idx]->next; // Adj(v)
    while(next) {
        next_idx  = next->key - 'a';
        next = next->next;
        if (g->headers[next_idx]->color == white) {
            g->headers[next_idx]->prev = g->headers[idx];
            dfs_visit(g, g->headers[next_idx]->key, time);
        }
    }
    g->headers[idx]->color = black;
    (*time)++;
    g->headers[idx]->final_time = (*time);
}

void dfs(struct graph *g) {
    assert(g);    
    for(int i = 0; i < g->num_vertexes; i++) {
        g->headers[i]->prev = NULL;
        g->headers[i]->color = white;
    }
    int time = 0;
    printf("dfs搜索结果: ");
    for(int i = 0; i < g->num_vertexes; i++) {
        if (g->headers[i]->color == white) {
            dfs_visit(g, g->headers[i]->key, &time);
        }
    }
    printf("\n");
}



int main() {
    int num_vertexes = 5;
    struct graph *graph = create_graph(num_vertexes);
    add_edge(graph, 'a', 'b');
    add_edge(graph, 'a', 'e');
    add_edge(graph, 'b', 'c');
    add_edge(graph, 'b', 'd');
    add_edge(graph, 'b', 'e');
    add_edge(graph, 'c', 'd');
    add_edge(graph, 'd', 'e');
    dfs(graph);
    free_graph(graph);
    return 0;
}