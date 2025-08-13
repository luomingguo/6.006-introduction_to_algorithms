import unittest
import merge_sort as sort
import time


class TestInsertSort(unittest.TestCase):

    def test_split(self):
        quiz = [8, 2, 4, 9, 3]
        ans = [2, 3, 4, 8, 9]
        sort.merge_sort(quiz)
        self.assertEqual(quiz, ans)

    def test_empty_list(self):
        quiz = []
        ans = []
        sort.merge_sort(quiz)
        self.assertEqual(quiz, ans)

    def test_single_element(self):
        quiz = [5]
        ans = [5]
        sort.merge_sort(quiz)
        self.assertEqual(quiz, ans)

    def test_already_sorted(self):
        quiz = [1, 2, 3, 4, 5]
        ans = [1, 2, 3, 4, 5]
        sort.merge_sort(quiz)
        self.assertEqual(quiz, ans)

    def test_reverse_sorted(self):
        quiz = [5, 4, 3, 2, 1]
        ans = [1, 2, 3, 4, 5]
        sort.merge_sort(quiz)
        self.assertEqual(quiz, ans)

    def test_duplicates(self):
        quiz = [5, 3, 8, 3, 2, 8, 1]
        ans = [1, 2, 3, 3, 5, 8, 8]
        sort.merge_sort(quiz)
        self.assertEqual(quiz, ans)

    def test_negative_numbers(self):
        quiz = [3, -1, -4, 2, 0]
        ans = [-4, -1, 0, 2, 3]
        sort.merge_sort(quiz)
        self.assertEqual(quiz, ans)

    # def test_performance(self):
    #     # Generate a large list of random numbers
    #     import random
    #     quiz = random.sample(range(10000), 10000)
    #     start_time = time.time()
    #     sort.merge_sort(quiz)
    #     end_time = time.time()
    #     duration = end_time - start_time
    #     print("Performance test took {duration:.4f} seconds")
    #     self.assertTrue(duration < 2, "Performance test failed: sorting took too long")

if __name__ == '__main__':
    unittest.main()
