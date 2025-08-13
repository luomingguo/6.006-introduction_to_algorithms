#include "binary_node.h"

typedef struct binary_tree {
    binary_node* root;
    int size;

} binary_tree;

binary_tree* binary_tree_new() {
    binary_tree *tree = (binary_tree*)malloc(sizeof(binary_tree));
    tree->root = NULL;
    tree->size = 0;
}

void binary_tree_iter(binary_tree *tree, void (*visit)(binary_node*)) {
    if (tree && tree->root) {
        subtree_iter(tree->root, visit);
    }
}



