from binary_node import Binary_Node

class Size_Node(Binary_Node):

    def subtree_update(self):
        super().subtree_update()
        self.size = 1
        if self.left:
            self.size += self.left.size
        if self.right:
            self.size += self.right.size
    
    def subtree_at(self, i):
        assert i >= 0
        L_size = 0
        if self.left:
            L_size = self.left.size
        if i < L_size:
            return self.left.subtree_at(i)
        elif i > L_size:
            return self.right.subtree_at(i - L_size - 1)
        else:
            return self
        

