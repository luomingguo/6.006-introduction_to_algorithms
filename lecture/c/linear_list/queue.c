#include "queue.h"

int main() {
    char data;
    struct queue* q = create_queue(4);
    assert(dequeue(q, &data)); //
    assert(!enqueue(q, 'a'));
    assert(!enqueue(q, 'b'));
    assert(!enqueue(q, 'c'));
    assert(!enqueue(q, 'd'));
    assert(enqueue(q, 'e'));
    assert(!dequeue(q, &data));
    assert(data == 'a');
    assert(!dequeue(q, &data));
    assert(data == 'b');
    assert(!dequeue(q, &data));
    assert(data == 'c');
    assert(!dequeue(q, &data));
    assert(data == 'd');
    assert(dequeue(q, &data));
    assert(!enqueue(q, 'f'));
    assert(!dequeue(q, &data));
    assert(data == 'f');
    free_queue(q);
    return 0;
}