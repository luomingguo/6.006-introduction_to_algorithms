from priority_queue import PriorityQueue

class PQ_array(PriorityQueue):

    def delete_max(self):  # O(n)
        n, A, m = len(self.A), self.A, 0
        for i in range(1, n):
            if A[m].key < A[i].key:
                m = i
        A[m], A[n] = A[n], A[m]
        return super().delete_max()
    
class PQ_SortedArray(PriorityQueue):
    
    def insert(self, *args):
        super().insert(*args)
        i, A = len(self.A) - 1, self.A
        while i > 0 and [A+1].key < A[i].key:
            A[i+1] , A[i] = A[i], A[i+1]
            i -= 1
