# Copyright 2021 GNDavydov

def merge_sort(array, cmp=lambda a, b: a < b):
    if len(array) < 2:
        return

    middle = len(array) // 2

    left_array = array[:middle]
    right_array = array[middle:]
    array.clear()

    merge_sort(left_array, cmp)
    merge_sort(right_array, cmp)
    merge(left_array, right_array, array, cmp)


def merge(array1, array2, result, cmp):
    i = j = 0

    while i != len(array1) and j != len(array2):
        if cmp(array1[i], array2[j]):
            result.append(array1[i])
            i += 1
        else:
            result.append(array2[j])
            j += 1

    result += array1[i:] + array2[j:]
