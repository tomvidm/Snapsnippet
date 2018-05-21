#include "gtest/gtest.h"
#include <boost/multiprecision/cpp_int.hpp>
#include "combinatorics.hpp"

TEST(TestCombinatorics, Combinations) {
    using snapsnip::combinations;

    EXPECT_EQ(combinations<long>(4, 0), 1);
    EXPECT_EQ(combinations<long>(4, 1), 4);
    EXPECT_EQ(combinations<long>(4, 2), 6);
    EXPECT_EQ(combinations<long>(4, 3), 4);
    EXPECT_EQ(combinations<long>(4, 4), 1);
    EXPECT_EQ(combinations<long>(4, 4), 1);
    EXPECT_EQ(combinations<long>(24, 16), 735471);
    EXPECT_EQ(combinations<long>(24, 12), 2704156);
}