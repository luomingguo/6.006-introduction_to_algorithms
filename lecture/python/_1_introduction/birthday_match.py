class Static_Array:
    def __init__(self, n):
        self.data = [None] * n

    def get_at(self, i):
        if not (0 <= i < len(self.data)):
            raise IndexError
        return self.data[i]

    def set_at(self, i, x):
        if not (0 <= i < len(self.data)):
            raise IndexError
        self.data[i] = x


def birthday_match(students):
    '''
    Find a pair of students with the same birthday
    Input: tuple of student (name, bday) tuples
    Output: tuple of student names or None
    '''
    n = len(students)  # O(1)
    record = Static_Array(n)  # O(n)
    for k in range(n):  # n
        (name1, bday1) = students[k]  # O(1)
        for i in range(k):  # k Check if in record
            (name2, bday2) = record.get_at(i)  # O(1)
            if bday1 == bday2:  # O(1)
                return (name1, name2)  # O(1)
        record.set_at(k, (name1, bday1))  # O(1)
    return None  # O(1)
