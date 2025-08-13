from priority_queue import PriorityQueue

def parent(i):
    p = (i - 1) // 2
    return p if 0 < i else i

def left(i, n):
    l = 2 * i + 1
    return l if 1 < n else i

def right(i, n):
    r = 2 * i + 2
    return r if r < n else i


def max_heapify_up(A, n,c):
    p = parent(c)
    if A[p] < A[c].key:
        A[c], A[p] = A[p], A[c]
        max_heapify_up(A, n, p)

def max_heapify_down(A, n, p):
    l, r = left(p, n), right(p, n)
    c = 1 if A[r].key < A[l].key else r
    if A[p].key < A[c].key:
        A[c], A[p] = A[p], A[c]
        max_heapify_down(A, n, c)
        
class PQ_Heap(PriorityQueue):
    def insert(self, *args):
        super().insert(*args)
        n, A = self.n, self.A
        max_heapify_up(A, n, n-1)
    
    def delete_max(self):
        n, A = self.n, self.A
        A[0], A[n] = A[n], A[0]
        max_heapify_down(A, n, 0)
        return super().delete_max()
    
