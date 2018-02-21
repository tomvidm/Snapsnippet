#include "gtest/gtest.h"
#include <iostream>
#include <limits>
#include "numbertheory.hpp"
#include <boost/multiprecision/cpp_int.hpp>

TEST(TestNumberTheory, CommonDivisor) {
    using snapsnip::findCommonDivisor;

    EXPECT_EQ(findCommonDivisor(10, 30), 10);
    EXPECT_EQ(findCommonDivisor(3, 9), 3);
    EXPECT_EQ(findCommonDivisor(5, 7), 1);
}

TEST(TestNumberTheory, FibonacciSeq) {
    using snapsnip::FibonacciSeq;
    EXPECT_EQ(FibonacciSeq<unsigned>::nthElement(0), 0);
    EXPECT_EQ(FibonacciSeq<unsigned>::nthElement(1), 1);
    EXPECT_EQ(FibonacciSeq<unsigned>::nthElement(2), 1);
    EXPECT_EQ(FibonacciSeq<unsigned>::nthElement(3), 2);
    EXPECT_EQ(FibonacciSeq<unsigned>::nthElement(4), 3);
    EXPECT_EQ(FibonacciSeq<unsigned>::nthElement(5), 5);
}

TEST(TestNumberTheory, CollatzSeq) {
    using snapsnip::CollatzSeq;
    CollatzSeq<unsigned> coll(17);
    EXPECT_EQ(coll.getSequence().size(), 13);
}

TEST(TestNumberTheory, ModExp) {
    using snapsnip::modexp;
    EXPECT_EQ(modexp<long>(0, 0, 0), 1);
    EXPECT_EQ(modexp<long>(0, 1, 0), 0);
    EXPECT_EQ(modexp<long>(1, 0, 0), 1);
    EXPECT_EQ(modexp<long>(1, 1, 0), 1);

    EXPECT_EQ(modexp<long>(5, 2, 0), 25);
    EXPECT_EQ(modexp<long>(5, 2, 10), 5);
    EXPECT_EQ(modexp<long>(5, 2, 5), 0);
}

TEST(TestNumberTheory, Tetration) {
    namespace mp = boost::multiprecision;
    using snapsnip::hyperexp;
    typedef mp::int512_t bigint;

    long long max = std::numeric_limits<long long>::max();
    EXPECT_EQ(hyperexp<bigint>(1, 1, max), 1);
    EXPECT_EQ(hyperexp<bigint>(1, 2, max), 1);
    EXPECT_EQ(hyperexp<bigint>(1, 3, max), 1);
    EXPECT_EQ(hyperexp<bigint>(2, 2, max), 4);
    EXPECT_EQ(hyperexp<bigint>(2, 3, max), 16);
    EXPECT_EQ(hyperexp<bigint>(2, 4, max), 65536);
    EXPECT_EQ(hyperexp<bigint>(3, 2, max), 27);
    EXPECT_EQ(hyperexp<bigint>(3, 3, max), 7625597484987);
}

