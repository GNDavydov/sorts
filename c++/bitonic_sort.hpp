// Copyright 2021 GNDavydov

#ifndef SORTING_BITONIC_SORT_HPP_
#define SORTING_BITONIC_SORT_HPP_

#include <algorithm>
#include <functional>

namespace bitonic_sort {
    template<class It, class Compare = std::less<>>
    inline void compareAndSwap(It iter_1, It iter_2, bool direction, Compare cmp) {
        if (cmp(*iter_1, *iter_2) != direction) std::iter_swap(iter_1, iter_2);
    }

    template<class It, class Compare = std::less<>>
    void merge(It first, It last, bool direction, Compare cmp) {
        const std::size_t distance = std::distance(first, last);

        if (distance < 2) return;

        It middle = std::next(first, distance / 2);
        It tmp1 = first;
        It tmp2 = middle;

        while (tmp2 != last) {
            compareAndSwap(tmp1, tmp2, direction, cmp);
            ++tmp1;
            ++tmp2;
        }

        merge(first, middle, direction, cmp);
        merge(middle, last, direction, cmp);
    }

    template<class It, class Compare = std::less<>>
    void sort(It first, It last, bool direction, Compare cmp) {
        const std::size_t distance = std::distance(first, last);

        if (distance < 2) return;

        It middle = std::next(first, distance / 2);
        sort(first, middle, 1, cmp);
        sort(middle, last, 0, cmp);

        merge(first, last, direction, cmp);
    }

    template<class It, class Compare = std::less<>>
    void bitonicSort(It first, It last, Compare cmp = Compare{}) {
        sort(first, last, 1, cmp);
    }
}


#endif //SORTING_BITONIC_SORT_HPP_
