"""
用ALV平衡实现的二叉树节点
"""

def height(A):
    if A: return A.height
    else: return -1

class Binary_Node:
    def __init__(self, x):              # O(1)
        self.item = x
        self.left = None
        self.right = None
        self.parent = None
        self.subtree_update()      # lec 7

    def subtree_update(self):
        self.height = 1 + max(height(self.left), height(self.right))

    def skew(self):
        return height(self.right) - height(self.left)
    
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
    
    # 后继（是二叉搜索树中大于当前节点的最小值节点）
    def successor(self):                # O(h)
        if self.right:
            return self.right.subtree_first()
        while self.parent and (self is self.parent.right):
            self = self.parent
        return self.parent
    
    # 前驱（是二叉搜索树中小于当前节点的最大值节点）
    def predecessor(self):              # O(h)
        if self.left:
            return self.left.subtree_last()
        while self.parent and (self is self.parent.left):
            self = self.parent
        return self.parent
    
    def subtree_insert_after(self, B):  # O(h)
        if self.right:
            self = self.right.subtree_first()
            self.left, B.parent = B, self
        else:
            self.right, B.parent = B, self
        self.maintain()
        
    def subtree_insert_before(self, B): # O(h)
        if self.left:
            self = self.left.subtree_last()
            self.right, B.parent = B, self
        else:
            self.left, B.parent = B, self
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


    """
        _____<D>_____           --right_roate->       _____<B>_____
    ___<B>___        <E>                           __<A>___       ___<D>___
    <A>    <C>      /    \                         /    \        <C>    <E> 
    /    \  /    \   / ---- \    <-left_rotate-  / ---  \      /    \  /    \
    / ---  \ / ---- \                                          / ---  \ / ---- \
    """
    def subtree_rotate_right(D):
        assert D.left
        B, E = D.left, D.right
        A, C = B.left, B.right
        D, B = B, D
        D.item, B.item = B.item, D.item
        B.left, B.right = A, D
        D.left, D.right = C, E
        if A:
            A.parent = B
        if E:
            E.parent = D
        B.subtree_update()
        D.subtree_update()

    def subtree_rotate_left(B):
        assert B.right
        A, D = B.left, B.right
        C, E = D.left, D.right
        B, D = D, B
        B.item, D.item = D.item, B.item
        D.left, D.right = B, E
        B.left, B.right = A, C
        if C:
            C.parent = B
        if E:
            E.parent = D

    def rebalance(self):
        if self.skew() == 2:
            if self.right.skew() < 0:
                self.right.subtree_ratate_right()
            self.subtree_rotate_left()
        elif self.skew() == -2:
            if self.left.skew() > 0:
                self.left.subtree_rotate_left()
            self.subtree_rotate_right()

    def maintain(self):
        self.rebalance()
        self.subtree_update()
        if self.parent:
            self.parent.maintain()
