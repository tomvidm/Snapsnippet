#include "gtest/gtest.h"

#include "ModularArithmetic.hpp"

TEST(TestModularArithmetic, iPow) {
    using namespace ma;

    EXPECT_EQ(iPow(2, 0), 1);
    EXPECT_EQ(iPow(2, 4), 16);
    EXPECT_EQ(iPow(3, 3), 27);
}