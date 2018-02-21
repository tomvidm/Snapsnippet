#include "gtest/gtest.h"

#include "fraction.hpp"

TEST(TestFraction, CommonDenominator) {
    using snapsnip::Fraction;
    Fraction<int> a(5, 3);
    Fraction<int> b(8, 6);
    Fraction<int> c_add(3, 1);
    Fraction<int> c_mult(20, 9);
    EXPECT_EQ(a + b, Fraction<int>(3, 1));
    EXPECT_EQ(a * b, Fraction<int>(20, 9));
    EXPECT_EQ(a / b, Fraction<int>(5, 4));
}