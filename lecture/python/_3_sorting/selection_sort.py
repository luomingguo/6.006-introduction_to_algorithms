
def selection_sort(A, i = None):
    """Sort A[:i+1]"""
    if i is None:
        i = len(A) - 1
    if i > 0:
        j = prefix_max(A, i)
        A[i], A[j] = A[j], A[i]
        selection_sort(A, i-1)

def prefix_max(A, i):
    """return index of maxmum in A[:i+1]"""
    if i > 0:
        j = prefix_max(A, i-1)
        if A[i] < A[j]:
            return j
    return i

"""非递归实现"""
# def selection_sort(A): # Selection sort array A
#     for i in range(len(A) - 1, 0, -1): # O(n) loop over array
#         m = i # O(1) initial index of max
#         for j in range(i): # O(i) search for max in A[:i]
#             if A[m] < A[j]: # O(1) check for larger value
#                 m = j # O(1) new max found
#         A[m], A[i] = A[i], A[m] # O(1) swap