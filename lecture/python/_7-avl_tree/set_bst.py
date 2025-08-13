"""
用二叉树实现Set的接口，用二叉树的遍历顺序来存储递增的key，
这种性质的树称为二叉搜索树（BST)
下面为二叉搜索树结构以及接口实现
"""
from binary_tree import Binary_Tree
from bst_node import BST_Node

class Set_Binary_Tree(Binary_Tree): # 二叉搜索树
    def __init__(self):
        super().__init__(BST_Node)
    
    def iter_order(self):
        yield from self
    
    def build(self, X):
        for x in X:
            self.insert(x)
    
    def find_min(self):
        if self.root:
            return self.root.subtree_first().item
        
    def find_max(self):
        if self.root:
            return self.root.subtree_last().item
        
    def find_next(self, k):
        if self.root:
            node =  self.root.subtree_find_next(k)
            if node:
                return node.item

    def find_prev(self, k):
        if self.root:
            node = self.root.subtree_find_prev(k)
            if node:
                return node.item
    
    def find(self, k):
        if self.root:
            node = self.root.subtree_find(k)
            if node:
                return node.item

    def insert(self, x):
        new_node = self.Node_Type(x)
        if self.root:
            self.root.subtree_insert(new_node)
            # 检查是否存在相同key值，如果是更新value，并返回false
            if new_node.parent is None: 
                return False 
        else:
            self.root = new_node
        self.size += 1
        return True
    
    def delete(self, k):
        assert self.root
        node = self.root.subtree_find(k)
        assert node
        ext = node.subtree_delete()
        if ext.parent is None:
            self.root = None
        self.size -= 1
        return ext.item






