def merge_sort(A, a = 0, b = None): # T(b - a = n)
    '''Sort A[a:b]'''
    if b is None: 
        b = len(A)                  # O(1)
    if 1 < b - a:                   # O(1)
        c = (a + b + 1) // 2        # O(1)
        merge_sort(A, a, c)         # T(n / 2)
        merge_sort(A, c, b)         # T(n / 2)
        L, R = A[a:c], A[c:b]       # O(n)
        merge(L, R, A, len(L), len(R), a, b) # S(n)

def merge(L, R, A, i, j, a, b):     # S(b - a = n)
    '''Merge sorted L[:i] and R[:j] into A[a:b]'''
    if a < b: # O(1)
        if (j <= 0) or (i > 0 and L[i - 1] > R[j - 1]): # O(1)
            A[b - 1] = L[i - 1]     # O(1)
            i = i - 1               # O(1)
        else:                       # O(1)
            A[b - 1] = R[j - 1]     # O(1)
            j = j - 1               # O(1)
        merge(L, R, A, i, j, a, b - 1)                  # S(n - 1)
