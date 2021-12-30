// Copyright 2021 GNDavydov

#ifndef SORTS_MERGE_SORT_HPP_
#define SORTS_MERGE_SORT_HPP_

#include <algorithm>
#include <functional>
#include <vector>

namespace merge_sort {
    template<class It, class Out, class Compare=std::less<>>
    void merge(It first1, It last1, It first2, It last2, Out out, Compare cmp) {
        while (first1 != last1 && first2 != last2) {
            if (cmp(*first1, *first2)) *out = *first1++;
            else *out = *first2++;
            ++out;
        }
        std::copy(first1, last1, out);
        std::copy(first2, last2, out);
    }

    template<class It, class Compare = std::less<>>
    void mergeSort(It first, It last, Compare cmp = Compare{}) {
        const std::size_t distance = std::distance(first, last);

        if (distance < 2) return;

        std::vector<typename It::value_type> buf(first, last);
        auto buf_middle = std::next(buf.begin(), distance / 2);

        mergeSort(buf.begin(), buf_middle, cmp);
        mergeSort(buf_middle, buf.end(), cmp);

        merge(buf.begin(), buf_middle, buf_middle, buf.end(), first, cmp);
    }
}


#endif //SORTS_MERGE_SORT_HPP_
