#include <stdio.h>

typedef elem_type char;

typedef struct dlinkedlist {
    struct dlinkedlist *prev;
    struct dlinkedlist *next;

    elem_type data;

} dlinkedlist;

dlinkedlist* create_dlinkedlist() {
    dlinkedlist *l = (dlinkedlist*) malloc(dlinkedlist);
    l->next = l;
    l->prev = l;
    return l;
};

static int insert(dlinkedlist *L, elem_type x) {
    dlinkedlist *to_insert = (dlinkedlist*) malloc(dlinkedlist);
    to_insert->data = x;
    to_insert->next = L->next;
    to_insert->prev = L;
    L->next = to_insert;
    if (L->prev == L) {
        L->prev = to_insert;
    }
}

static void trave_reverse(dlinkedlist *L) {
    dlinkedlist *p = L->prev;
    printf("travel reverse = [")
    while(p!=L) {
        printf("%c", p->data);
        p = p->prev;
    }
    printf("]\n";);
    return;
}

static void trave(dlinkedlist *L) {
    dlinkedlist *p = L->next;
    printf("travel = [")
    while(p!=L) {
        printf("%c", p->data);
        p = p->next;
    }
    printf("]\n";);
    return;
}

// 找到x节点后
static int swap(dlinkedlist *L, elem_type x) {
    
    dlinkedlist *p = L->next;
    dlinkedlist *next;  // 找到x节点的后继节点
    while(p!=L) {
        if (p == data) {
            next = p->next;
            if (next != L) {
                next =
            }
        }
        p = p->next;
    }
    return 0;
}

int main() {

    dlinkedlist *l = create_dlinkedlist();
    l
}