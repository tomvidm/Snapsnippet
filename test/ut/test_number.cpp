#include "gtest/gtest.h"
#include <iostream>
#include "number.hpp"
#include <boost/multiprecision/cpp_int.hpp>

TEST(TestNumber, Construction) {
    using snapsnip::Number;

    using ulong = unsigned long;

    std::array<ulong, 5> moduli = {5, 7, 9, 11, 13};

    const Number<ulong, 5> n1(300, moduli);
    const Number<ulong, 5> n2(200, moduli);
    const Number<ulong, 5> n3 = n1 * n2;

    EXPECT_EQ(n1.data[0], 0);
    EXPECT_EQ(n1.data[1], 6);
    EXPECT_EQ(n1.data[2], 3);
    EXPECT_EQ(n1.data[3], 3);
    EXPECT_EQ(n1.data[4], 1);
    EXPECT_EQ(n2.data[0], 0);
    EXPECT_EQ(n2.data[1], 4);
    EXPECT_EQ(n2.data[2], 2);
    EXPECT_EQ(n2.data[3], 2);
    EXPECT_EQ(n2.data[4], 5);
    EXPECT_EQ(n3.data[0], 0);
    EXPECT_EQ(n3.data[1], 3);
    EXPECT_EQ(n3.data[2], 6);
    EXPECT_EQ(n3.data[3], 6);
    EXPECT_EQ(n3.data[4], 5);
}