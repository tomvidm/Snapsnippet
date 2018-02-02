#include "gtest/gtest.h"

#include "numbertheory.hpp"

TEST(TestNumberTheory, FibonacciSeq) {
    using snapsnip::FibonacciSeq;
    EXPECT_EQ(FibonacciSeq<unsigned>::nthElement(0), 0);
    EXPECT_EQ(FibonacciSeq<unsigned>::nthElement(1), 1);
    EXPECT_EQ(FibonacciSeq<unsigned>::nthElement(2), 1);
    EXPECT_EQ(FibonacciSeq<unsigned>::nthElement(3), 2);
    EXPECT_EQ(FibonacciSeq<unsigned>::nthElement(4), 3);
    EXPECT_EQ(FibonacciSeq<unsigned>::nthElement(5), 5);
}