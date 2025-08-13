/*
    最小生成树
        普里姆算法 *
            本代码用了两种数据结构实现， 一个二叉堆实现的优先级队列， 一个是斐波那契堆
        克鲁斯算法
*/
#include <stdio.h>

#include "graph.h"


void mst_prim(struct graph* g, int (*weight)(struct graph*, 
        vertex, vertex), vertex s) {

                                

}

int main(int argc, char **argv) {
    int num_vertexes = 5;
    struct graph *graph = create_graph(num_vertexes);
    add_edge_with_weight(graph, 'a', 'b', 2);
    add_edge_with_weight(graph, 'a', 'e', 4);
    add_edge_with_weight(graph, 'b', 'c', 2);
    add_edge_with_weight(graph, 'b', 'd', 4);
    add_edge_with_weight(graph, 'b', 'e', 9);
    add_edge_with_weight(graph, 'c', 'd', 3 );
    add_edge_with_weight(graph, 'd', 'e', 1);
    mst_prim(g, weight, );
    free_graph(graph);
    return 0;
}