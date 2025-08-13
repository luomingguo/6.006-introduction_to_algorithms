#include <stdlib.h>

typedef struct binary_node {
    struct binary_node *parent;
    struct binary_node *left;
    struct binary_node *right;
    void *data;
} binary_node;

// 函数指针类型
typedef int   (*compare_func)(void* a, void* b);
typedef void  (*print_func)(void* item);
typedef void  (*free_func)(void* item);

binary_node* new_node(void *item) {
    binary_node* node = (binary_node*)malloc(sizeof(binary_node));
    node->data = item;
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;
    return node;
}

void binary_node_swap(binary_node* a, binary_node* b) {
    void* c = a->data;
    a->data = b->data;
    b->data = c;
}

void subtree_iter(binary_node* node, void (*visit)(binary_node*)) {
    if (!node) return;
    if (node->left) subtree_iter(node->left, visit);
    visit(node);
    if (node->right) subtree_iter(node->right, visit);
}

binary_node*  subtree_first(binary_node* node) {
    if (!node) return NULL;
    while (node->left) node = node->left;
    return node;
}

binary_node* subtree_last(binary_node* node) {
    if (!node) return NULL;
    while(node->right) node = node->right;
    return node;
}

binary_node* predecessor(binary_node* node) {
    if(!node) return NULL;
    if(node->left) return subtree_last(node->left);
    while(node->parent && node->parent->left && node->parent->left == node)
        node = node->parent;
    return node->parent;
}

binary_node* successor(binary_node* node) {
    if(!node) return NULL;
    if(node->right) return subtree_first(node->right);
    while(node->parent && node->parent->right && node->parent->right == node)
        node = node->parent;
    return node->parent;
}

void subtree_insert_after(binary_node* node, binary_node* other) {
    if (!node->right) {
        node->right = other;
        other->parent = node;
    } else {
        binary_node* c = subtree_first(node->right);
        c->left = other;
        other->parent = c;
    }
    // maintain(node); 
}

void subtree_insert_before(binary_node* node, binary_node* other) {
    if (!node->left) {
        node->left = other;
        other->parent = node;
    } else {
        binary_node* c = subtree_last(node->left);
        c->right = other;
        other->parent = c;
    }
    // maintain(node);
}

void subtree_delete(binary_node* node, free_func destroy) {
    
    if (node->left) {
        binary_node* c = predecessor(node);
        binary_node_swap(c, node);
        subtree_delete(c, destroy);
    } else if (node->right) {
        binary_node* c = successor(node);
        binary_node_swap(c, node);
        subtree_delete(c, destroy);
    } else {
        if(node->parent) {
            if(node->parent->left == node) {
                node->parent->left = NULL;
            } else {
                node->parent->right = NULL;
            }
            // maintain(node);
        }
        if (destroy) {
            destroy(node->data);
        }
        free(node);
    }
}

void rotate_left(binary_node* node) {
    

}

//       A
//      /  \
//     E     B
//   /  \   / \ 
//   F   G  C   D

//       A
//      /  \
//     E     B  
//          / \ 
//         C   D


//       B
//      /  \
//     A     D  
//    /  \   
//  E      C    