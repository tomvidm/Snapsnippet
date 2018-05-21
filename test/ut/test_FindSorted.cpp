#include "gtest/gtest.h"

#include <vector>

#include "FindSorted.hpp"

TEST(TestAlgorithms, findSorted) {
    using namespace ma;

    std::vector<int> sortedList{
        1,3,5,6,7,10,15,20,21
    };

    EXPECT_EQ(findIndexOf(1, sortedList), 0);
    EXPECT_EQ(findIndexOf(3, sortedList), 1);
    EXPECT_EQ(findIndexOf(5, sortedList), 2);
    EXPECT_EQ(findIndexOf(6, sortedList), 3);
    EXPECT_EQ(findIndexOf(21, sortedList), 8);
}