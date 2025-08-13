class Direct_Access_Array:
    def __init__(self, u):
        self.A = [None] * u
    
    def find(self, k):
        return self.A[k]
    
    def insert(self, x):
        self.A[x.key] = x
    
    def delete(self, k):
        self.A[k] = None
    
    def find_next(self, k):