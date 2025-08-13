"""
二叉树节点，是一个通用数据结构。
- 用于集合接口形成BST
- 用于序列接口形成序列二叉树
"""

class Binary_Node:
    def __init__(self, x):              # O(1)
        self.item = x
        self.left = None
        self.right = None
        self.parent = None
        #self.subtree_update()      # lec 7

    def subtree_iter(self):             # O(n)
        if self.left: 
            yield from self.left.subtree_iter()
        yield self
        if self.right: 
            yield from self.right.subtree_iter()
    
    def subtree_first(self):            # O(h)
        if self.left: 
            return self.left.subtree_first()
        else:
            return self
    
    def subtree_last(self):             # O(h)
        if self.right:
            return self.right.subtree_last()
        else:
            return self
    
    def successor(self):                # O(h)
        if self.right:
            return self.right.subtree_first()
        while self.parent and (self is self.parent.left):
            self = self.parent
        return self.parent
    
    def predecessor(self):              # O(h)
        if self.left:
            return self.left.subtree_first()
        while self.parent and (self is self.parent.left):
            self = self.parent
        return self.parent
    
    def subtree_insert_after(self, B):  # O(h)
        if not self.right:
            self.right = B
            B.parent = self
        else:
            C = self.right.subtree_first()
            C.left = B
            B.parent = C
        self.maintain()
        
    def subtree_insert_before(self, B): # O(h)
        if not self.left:
            self.left = B
            B.parent = self
        else:
            C = self.left.subtree_last()
            C.right = B
            B.parent = C
        self.maintain()

    def subtree_delete(self):          # O(h)
        if self.left or self.right:
            B = None
            if self.left:
                B = self.predecessor()
            else:
                B = self.successor()
            self.item, B.item = B.item, self.item
            return B.subtree_delete()
        if self.parent:
            if self.parent.left is self:
                self.parent.left = None
            else:
                self.parent.right = None
            self.maintain()
        return self

    def maintain(self):
        pass