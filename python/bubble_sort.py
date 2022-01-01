# Copyright 2021 GNDavydov

def bubble_sort(array, cmp=lambda a, b: a < b):
    for i in range(0, len(array) - 1):
        for j in range(i + 1, len(array)):
            if not cmp(array[i], array[j]):
                array[i], array[j] = array[j], array[i]
