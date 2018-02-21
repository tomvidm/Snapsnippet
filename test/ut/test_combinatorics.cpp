#include "gtest/gtest.h"
#include <boost/multiprecision/cpp_int.hpp>
#include "combinatorics.hpp"

TEST(TestCombinatorics, Combinations) {
    using snapsnip::combinations;

    namespace mp = boost::multiprecision;
    typedef mp::uint256_t bigint;

    EXPECT_EQ(combinations<bigint>(4, 0), 0);
    EXPECT_EQ(combinations<bigint>(4, 1), 4);
    EXPECT_EQ(combinations<bigint>(4, 2), 6);
    EXPECT_EQ(combinations<bigint>(4, 3), 4);
    EXPECT_EQ(combinations<bigint>(4, 4), 1);
    EXPECT_EQ(combinations<bigint>(4, 4), 1);
    EXPECT_EQ(combinations<bigint>(24, 16), 735471);
    EXPECT_EQ(combinations<bigint>(24, 12), 2704156);
    EXPECT_EQ(combinations<bigint>(52, 26), 495918532948104);
    //EXPECT_EQ(combinations<bigint>(100, 50), 100891344545564193334812497256);
}