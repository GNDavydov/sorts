// Copyright 2021 GNDavydov

#include <gtest/gtest.h>

#include <bitonic_sort.hpp>
#include <bubble_sort.hpp>
#include <merge_sort.hpp>
#include <quick_sort.hpp>

#include <algorithm>
#include <vector>
#include <random>

class TestGenerationEnvironment : public testing::Test {
protected:
    std::vector<std::size_t> vec1;

    std::vector<std::size_t> vec_case_1;
    std::vector<std::size_t> vec_case_2;
    std::vector<std::size_t> vec_case_3;

public:
    TestGenerationEnvironment() : vec1(512) {
        for (auto &el: vec1) el = random();
        vec_case_1 = vec1;
        vec_case_2 = vec1;
        vec_case_3 = vec1;
    }

    void SetUp() override {
        std::sort(vec_case_1.begin(), vec_case_1.end());
        std::sort(vec_case_2.begin(), vec_case_2.end(), [](auto a, auto b) { return a <= b; });
        std::sort(vec_case_3.begin(), vec_case_3.end(), [](auto a, auto b) { return a > b; });
    }
};

TEST_F(TestGenerationEnvironment, BubbleSort) {
    std::vector<std::size_t> test_vec_1(vec1);
    std::vector<std::size_t> test_vec_2(vec1);
    std::vector<std::size_t> test_vec_3(vec1);

    bubble_sort::bubbleSort(test_vec_1.begin(), test_vec_1.end());
    EXPECT_EQ(test_vec_1, vec_case_1);
    bubble_sort::bubbleSort(test_vec_2.begin(), test_vec_2.end(), [](auto a, auto b) { return a <= b; });
    EXPECT_EQ(test_vec_2, vec_case_2);
    bubble_sort::bubbleSort(test_vec_3.begin(), test_vec_3.end(), [](auto a, auto b) { return a > b; });
    EXPECT_EQ(test_vec_3, vec_case_3);
}

TEST_F(TestGenerationEnvironment, BitonicSort) {
    std::vector<std::size_t> test_vec_1(vec1);
    std::vector<std::size_t> test_vec_2(vec1);
    std::vector<std::size_t> test_vec_3(vec1);

    bitonic_sort::bitonicSort(test_vec_1.begin(), test_vec_1.end());
    EXPECT_EQ(test_vec_1, vec_case_1);
    bitonic_sort::bitonicSort(test_vec_2.begin(), test_vec_2.end(), [](auto a, auto b) { return a <= b; });
    EXPECT_EQ(test_vec_2, vec_case_2);
    bitonic_sort::bitonicSort(test_vec_3.begin(), test_vec_3.end(), [](auto a, auto b) { return a > b; });
    EXPECT_EQ(test_vec_3, vec_case_3);
}

TEST_F(TestGenerationEnvironment, MergeSort) {
    std::vector<std::size_t> test_vec_1(vec1);
    std::vector<std::size_t> test_vec_2(vec1);
    std::vector<std::size_t> test_vec_3(vec1);

    merge_sort::mergeSort(test_vec_1.begin(), test_vec_1.end());
    EXPECT_EQ(test_vec_1, vec_case_1);
    merge_sort::mergeSort(test_vec_2.begin(), test_vec_2.end(), [](auto a, auto b) { return a <= b; });
    EXPECT_EQ(test_vec_2, vec_case_2);
    merge_sort::mergeSort(test_vec_3.begin(), test_vec_3.end(), [](auto a, auto b) { return a > b; });
    EXPECT_EQ(test_vec_3, vec_case_3);
}

TEST_F(TestGenerationEnvironment, QuickSort) {
    std::vector<std::size_t> test_vec_1(vec1);
    std::vector<std::size_t> test_vec_2(vec1);
    std::vector<std::size_t> test_vec_3(vec1);

    quick_sort::quickSort(test_vec_1.begin(), test_vec_1.end());
    EXPECT_EQ(test_vec_1, vec_case_1);
    quick_sort::quickSort(test_vec_2.begin(), test_vec_2.end(), [](auto a, auto b) { return a <= b; });
    EXPECT_EQ(test_vec_2, vec_case_2);
    quick_sort::quickSort(test_vec_3.begin(), test_vec_3.end(), [](auto a, auto b) { return a > b; });
    EXPECT_EQ(test_vec_3, vec_case_3);
}

