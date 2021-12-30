// Copyright 2021 GNDavydov

#ifndef SORTS_BUBBLE_SORT_HPP_
#define SORTS_BUBBLE_SORT_HPP_

#include <algorithm>
#include <functional>

namespace bubble_sort {
    template<class It, class Compare=std::less<>>
    void bubbleSort(It first, It last, Compare cmp = Compare{}) {
        for (auto i = first; i != std::prev(last); ++i) {
            for (auto j = std::next(i); j != last; ++j) {
                if (!cmp(*i, *j)) std::iter_swap(i, j);
            }
        }
    }
}

#endif //SORTS_BUBBLE_SORT_HPP_
