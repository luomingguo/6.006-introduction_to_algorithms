/*
    最小生成树
        普里姆算法
        克鲁斯算法 *
*/
#include <stdio.h>

#include "graph.h"


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