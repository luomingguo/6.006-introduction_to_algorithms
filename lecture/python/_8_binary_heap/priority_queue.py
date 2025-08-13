class PriorityQueue:
    def __init__(self):
        self.n = 0
        self.A = []
    
    def insert(self):
        if not self.n < len(self.A):
            raise IndexError("insert full priority queue")
        self.n += 1

    def delete_max(self):
        if len(self.A) < 1:
            raise IndexError("pop from empty priority queue")
        self.n -= 1
    
    @classmethod
    def sort(Queue, A):
        pq = Queue(A)
        for x in A:
            pq.insert(x)
        out = [pq.delete_max() for _ in A] 
        out.reverse()
        return out
