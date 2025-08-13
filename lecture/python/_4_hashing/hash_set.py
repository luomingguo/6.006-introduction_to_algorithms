import os
import sys
from random import randint
# Add project root to sys.path
lecture_root = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
sys.path.append(lecture_root)

from _2_data_structure.set_from_seq import Set_from_Seq
from _2_data_structure.linked_list_seq import Linked_List_Seq

class Hash_Table_Set:
    def __init__(self, r = 200):                
        self.chain_set = Set_from_Seq(Linked_List_Seq)
        self.A = []
        self.size = 0
        self.r = r
        self.p = 2**31 - 1
        self.a = randint(1, self.p - 1)
        self._compute_bounds()
        self._resize(0)
    
    def __len__(self):
        return self.size
    
    def __iter__(self):
        for X in self.A:
            yield from X
    
    def _compute_bounds(self):
        self.upper = len(self.A)
        self.lower = len(self.A) * 100 * 100 // (self.r * self.r)

    def _resize(self, n):
        if (self.lower >= n) or (n >= self.upper):
            f = self.r // 100
            if self % 100:
                f += 1
            # f = ceil(r / 100)
            m = max(n, 1) * f
            A = [self.chain_set() for _ in range(m)]
            for x in self:
                h = self._hash(x.key, m)
                A[h].insert(x)
            self.A = A
            self._compute_bounds()

    def find(self, k):
        h = self._hash(k, len(self.A))
        return self.A[h].find(k)

    def build(self, X):
        for x in X:
            self.insert(x)
    
    def _hash():
        pass

    def insert(self, x):
        self._resize(self.size + 1)
        h = self._hash(x.key, len(self.A))
        added = self.A[h].insert(x)
        if added:
            self.size += 1
        return added
    
    def 
    
