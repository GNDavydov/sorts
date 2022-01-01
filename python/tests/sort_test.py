# Copyright 2021 GNDavydov

import unittest
import random

from bubble_sort import bubble_sort
from merge_sort import merge_sort
from quick_sort import quick_sort


class TestSorts(unittest.TestCase):
    def setUp(self):
        self.unsorted_array_1 = [random.randint(0, 1000) for i in range(256)]
        self.unsorted_array_2 = [random.randint(0, 1000) for i in range(100)]

        self.sorted_array_1 = self.unsorted_array_1.copy()
        self.sorted_array_1.sort()
        self.sorted_array_2 = self.unsorted_array_2.copy()
        self.sorted_array_2.sort(reverse=True)

    def test_bubble_sort(self):
        bubble_sort(self.unsorted_array_1)
        self.assertEqual(self.unsorted_array_1, self.sorted_array_1)
        bubble_sort(self.unsorted_array_2, lambda x, y: x > y)
        self.assertEqual(self.unsorted_array_2, self.sorted_array_2)

    def test_merge_sort(self):
        merge_sort(self.unsorted_array_1)
        self.assertEqual(self.unsorted_array_1, self.sorted_array_1)
        merge_sort(self.unsorted_array_2, lambda x, y: x > y)
        self.assertEqual(self.unsorted_array_2, self.sorted_array_2)

    def test_quick_sort(self):
        self.unsorted_array_1 = quick_sort(self.unsorted_array_1)
        self.assertEqual(self.unsorted_array_1, self.sorted_array_1)
        self.unsorted_array_2 = quick_sort(self.unsorted_array_2, lambda x, y: x > y)
        self.assertEqual(self.unsorted_array_2, self.sorted_array_2)
