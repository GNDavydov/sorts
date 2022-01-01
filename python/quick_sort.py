# Copyright 2021 GNDavydov

def quick_sort(array, cmp=lambda a, b: a < b):
    if len(array) < 2:
        return array

    pivot = array[0]
    less = [i for i in array[1:] if cmp(i, pivot)]
    greater = [i for i in array[1:] if not cmp(i, pivot)]
    return quick_sort(less, cmp) + [pivot] + quick_sort(greater, cmp)
