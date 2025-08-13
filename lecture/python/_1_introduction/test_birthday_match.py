import unittest
from birthday_match import birthday_match

class TestBirthdayMatch(unittest.TestCase):

    def test_no_match(self):
        students = [
            ("Alice", "01/01"),
            ("Bob", "02/02"),
            ("Charlie", "03/03"),
            ("David", "04/04")
        ]
        self.assertIsNone(birthday_match(students))

    def test_one_match(self):
        students = [
            ("Alice", "01/01"),
            ("Bob", "02/02"),
            ("Charlie", "01/01"),
            ("David", "04/04")
        ]
        result = birthday_match(students)
        self.assertTrue(
            (result == ("Alice", "Charlie") or result == ("Charlie", "Alice"))
        )

    def test_multiple_matches(self):
        students = [
            ("Alice", "01/01"),
            ("Bob", "02/02"),
            ("Charlie", "01/01"),
            ("David", "02/02")
        ]
        # Either pair ("Alice", "Charlie") or ("Bob", "David") is a valid match
        result = birthday_match(students)
        self.assertTrue(
            (result == ("Alice", "Charlie") or result == ("Charlie", "Alice")) or
            (result == ("Bob", "David") or result == ("David", "Bob"))
        )

    def test_empty_input(self):
        students = []
        self.assertIsNone(birthday_match(students))

    def test_single_student(self):
        students = [("Alice", "01/01")]
        self.assertIsNone(birthday_match(students))

if __name__ == '__main__':
    unittest.main()