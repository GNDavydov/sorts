// Copyright 2021 GNDavydov

#ifndef SORTS_QUICK_SORT_HPP_
#define SORTS_QUICK_SORT_HPP_

#include <algorithm>
#include <functional>


namespace quick_sort {
    template<class It, class Compare=std::less<>>
    void quickSort(It first, It last, Compare cmp = Compare{}) {
        const std::size_t distance = std::distance(first, last);
        if (distance < 2) return;

        const auto pivot = *first;
        auto pivot_pos = std::partition(first, last, [&pivot, &cmp](auto &item) {
            return cmp(item, pivot);
        });

        auto iter = std::find(first, last, pivot);
        if (pivot_pos > iter) {
            std::iter_swap(iter, std::prev(pivot_pos));
            pivot_pos = std::prev(pivot_pos);
        } else {
            std::iter_swap(pivot_pos, iter);
        }

        quickSort(first, pivot_pos, cmp);
        quickSort(std::next(pivot_pos), last, cmp);
    }
}


#endif //SORTS_QUICK_SORT_HPP_
