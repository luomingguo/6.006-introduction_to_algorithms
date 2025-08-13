"""
用二叉树实现Set的接口，用二叉树的遍历顺序来存储递增的key，
这种性质的树称为二叉搜索树（BST)
下面为二叉搜索树节点数据结构
"""
from binary_node import Binary_Node

class BST_Node(Binary_Node):
    def subtree_find(self, k):              # O(h)
        if k < self.item.key:
            if self.left: 
                return self.left.subtree_find(k)
        elif k > self.item.key:
            if self.right:
                return self.right.subtree_find(k)
        else:
            return self
        return None
    
    def subtree_find_prev(self, k):         # O(h)
        if k < self.item.key:
            if self.left:
                return self.left.subtree_find_prev(self, k)
            else:
                return None
        elif self.right:
            B = self.right.subtree_find_prev(k)
            if B:
                return B
        return self

    def subtree_find_next(self, k):         # O(h)   
        if k > self.item.key:
            if self.right:
                return self.right.subtree_find_prev(self, k)
            else:
                return None
        elif self.left:
            B = self.left.subtree_find_prev(k)
            if B:
                return B
        return self
    
    # 与二叉树的方法略有不同，因此需要重写
    def subtree_insert(self, B):               # O(h)
        if B.item.key < self.item.key:
            if self.left: 
                self.left.subtree_insert(B)
            else:
                self.subtree_insert_before(B)
        elif B.item.key > self.item.key:
            if self.right:
                self.right.subtree_insert(B)
            else:
                self.subtree_insert_after(B)
        else:
            self.item = B.item