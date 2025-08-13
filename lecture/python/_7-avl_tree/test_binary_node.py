import unittest
from binary_node import Binary_Node, height
class TestAVLTree(unittest.TestCase):

    def test_avl_tree_insert(self):
        root = Binary_Node(10)
        node1 = Binary_Node(5)
        node2 = Binary_Node(15)

        # 插入节点
        root.subtree_insert_before(node1)
        root.subtree_insert_after(node2)

        # 验证插入后树的结构
        self.assertEqual(root.left.item, 5)
        self.assertEqual(root.right.item, 15)
        self.assertEqual(root.height, 1 + max(height(root.left), height(root.right)))

    def test_avl_tree_rebalance(self):
        root = Binary_Node(10)
        node1 = Binary_Node(5)
        node2 = Binary_Node(2)

        # 插入节点导致不平衡
        root.subtree_insert_before(node1)
        root.subtree_insert_before(node2)

        # # 触发重平衡
        # node1.maintain()

        # 验证旋转后的结构
        self.assertEqual(root.item, 5)
        self.assertEqual(root.left.item, 2)
        self.assertEqual(root.right.item, 10)

    def test_avl_tree_delete(self):
        root = Binary_Node(10)
        node1 = Binary_Node(5)
        node2 = Binary_Node(15)
        node3 = Binary_Node(3)

        root.subtree_insert_before(node1)
        root.subtree_insert_after(node2)
        node1.subtree_insert_before(node3)

        # 删除节点
        deleted_node = node1.subtree_delete()

        # 验证删除后的结构
        self.assertEqual(root.left.item, 3)
        self.assertEqual(deleted_node.item, 5)

    def test_avl_tree_successor_predecessor(self):
        root = Binary_Node(10)
        node1 = Binary_Node(5)
        node2 = Binary_Node(15)
        node3 = Binary_Node(2)
        node4 = Binary_Node(7)

        root.subtree_insert_before(node1)
        root.subtree_insert_after(node2)
        node1.subtree_insert_before(node3)
        node1.subtree_insert_after(node4)

        # 测试前驱和后继
        self.assertEqual(node1.successor().item, 7)
        self.assertEqual(node2.predecessor().item, 10)


if __name__ == "__main__":
    unittest.main()
