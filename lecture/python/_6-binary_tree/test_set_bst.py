import unittest
from set_bst import Set_Binary_Tree
from bst_node import BST_Node

class TestSetBinaryTree(unittest.TestCase):

    def setUp(self):
        self.tree = Set_Binary_Tree()
        self.items = [5, 3, 8, 1, 4, 7, 10]

    def test_insert(self):
        for item in self.items:
            self.assertTrue(self.tree.insert(item))
        # 检查插入重复项
        self.assertFalse(self.tree.insert(5))

    def test_find(self):
        for item in self.items:
            self.tree.insert(item)
        for item in self.items:
            self.assertEqual(self.tree.find(item), item)
        # 测试查找不存在的元素
        self.assertIsNone(self.tree.find(99))

    def test_find_min(self):
        for item in self.items:
            self.tree.insert(item)
        self.assertEqual(self.tree.find_min(), 1)

    def test_find_max(self):
        for item in self.items:
            self.tree.insert(item)
        self.assertEqual(self.tree.find_max(), 10)

    def test_find_next(self):
        for item in self.items:
            self.tree.insert(item)
        self.assertEqual(self.tree.find_next(3), 4)
        self.assertEqual(self.tree.find_next(4), 5)
        self.assertIsNone(self.tree.find_next(10))  # 10 是最大值，没有后继

    def test_find_prev(self):
        for item in self.items:
            self.tree.insert(item)
        self.assertEqual(self.tree.find_prev(4), 3)
        self.assertEqual(self.tree.find_prev(5), 4)
        self.assertIsNone(self.tree.find_prev(1))  # 1 是最小值，没有前驱

    def test_delete(self):
        for item in self.items:
            self.tree.insert(item)
        self.assertEqual(self.tree.delete(1), 1)
        self.assertIsNone(self.tree.find(1))
        self.assertEqual(self.tree.delete(5), 5)
        self.assertIsNone(self.tree.find(5))
        # 测试删除不存在的元素
        with self.assertRaises(AssertionError):
            self.tree.delete(99)

if __name__ == '__main__':
    unittest.main()