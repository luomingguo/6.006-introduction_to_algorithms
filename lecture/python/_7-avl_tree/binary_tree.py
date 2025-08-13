from binary_node import Binary_Node
class Binary_Tree:
    def __init__(self, Node_Type = Binary_Node):
        self.root = None
        self.size = 0
        self.Node_Type = Node_Type
    
    def __len__(self): 
        return self.size
    def __iter__(self):
        if self.root:
            for A in self.root.subtree_iter():
                yield A.item
    