#include "graph.h"

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

    print_graph(graph);
    free_graph(graph);
    return 0;
}
