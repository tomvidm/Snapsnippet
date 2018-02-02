#include "gtest/gtest.h"

#include "modulararithmetic.hpp"

TEST(TestModularArithmetic, ModExp) {
    using snapsnip::modPow;
    EXPECT_EQ(modPow<long>(3, 1, 7), 3);
    EXPECT_EQ(modPow<long>(3, 2, 7), 2);
    EXPECT_EQ(modPow<long>(3, 3, 7), 6);
    EXPECT_EQ(modPow<long>(3, 4, 7), 4);
    EXPECT_EQ(modPow<long>(3, 5, 7), 5);
}