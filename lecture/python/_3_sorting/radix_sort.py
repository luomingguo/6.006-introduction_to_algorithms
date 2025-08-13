"""
	基数排序（Radix sort） 结合 计数排序（counting_sort）和元组排序（Tuple Sort）
"""


def counting_sort(A):
    "Sort A assuming items have non-negative keys"
    u = 1 + max([x.key for x in A])  # 查找最大键
    D = [[] for i in range(u)]       # 直接访问数组的链表
    for x in A:
        D[x.key].append(x)           # 在键为 x.key 的链表中插入元素
    i = 0
    for chain in D:                  # 按顺序读取每个链表中的元素
        for x in chain:
            A[i] = x
            i += 1

def radix_sort(A):
    "Sort A assuming items have non-negative keys"
    n = len(A)
    u = 1 + max([x.key for x in A])  # O(n) 找到最大键
    c = 1 + (u.bit_length() // n.bit_length())
    class Obj: pass
    D = [Obj() for a in A]
    for i in range(n):  # O(nc) 构造数字元组
        D[i].digits = []
        D[i].item = A[i]
        high = A[i].key
        for j in range(c):  # O(c) 生成数字元组
            high, low = divmod(high, n)
            D[i].digits.append(low)
    for i in range(c):  # O(nc) 对每一位数字排序
        for j in range(n):  # O(n) 将第 i 位作为键分配给元组
            D[j].key = D[j].digits[i]
        counting_sort(D)  # O(n) 对第 i 位数字排序
    for i in range(n):  # O(n) 输出到 A
        A[i] = D[i].item

# 测试代码
class Item:
    def __init__(self, key):
        self.key = key

A = [Item(170), Item(45), Item(75), Item(90), Item(802), Item(24), Item(2), Item(66)]


radix_sort(A)

for item in A:
    print(item.key)