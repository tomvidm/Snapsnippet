#include "gtest/gtest.h"
#include <iostream>
#include <limits>
#include "numbertheory.hpp"
#include <boost/multiprecision/cpp_int.hpp>

TEST(TestNumberTheory, CommonDivisor) {
    using snapsnip::gcd_iterative;

    EXPECT_EQ(gcd_iterative(10, 30), 10);
    EXPECT_EQ(gcd_iterative(3, 9), 3);
    EXPECT_EQ(gcd_iterative(5, 7), 1);
}

TEST(TestNumberTheory, FibonacciSeq) {
    using snapsnip::FibonacciSeq;
    EXPECT_EQ(FibonacciSeq<unsigned>::nthElement(0), 0);
    EXPECT_EQ(FibonacciSeq<unsigned>::nthElement(1), 1);
    EXPECT_EQ(FibonacciSeq<unsigned>::nthElement(2), 1);
    EXPECT_EQ(FibonacciSeq<unsigned>::nthElement(3), 2);
    EXPECT_EQ(FibonacciSeq<unsigned>::nthElement(4), 3);
    EXPECT_EQ(FibonacciSeq<unsigned>::nthElement(5), 5);
    EXPECT_EQ(FibonacciSeq<unsigned>::nthElement(6), 8);
    EXPECT_EQ(FibonacciSeq<unsigned>::nthElement(40), 102334155);
}

TEST(TestNumberTheory, PrimeNumbers) {
    using snapsnip::PrimeNumbers;
    EXPECT_EQ(PrimeNumbers<unsigned>::nthPrime(0), 2);
    EXPECT_EQ(PrimeNumbers<unsigned>::nthPrime(1), 3);
    EXPECT_EQ(PrimeNumbers<unsigned>::nthPrime(2), 5);
    EXPECT_EQ(PrimeNumbers<unsigned>::nthPrime(5), 13);
    EXPECT_EQ(PrimeNumbers<unsigned>::nthPrime(2), 5);
    EXPECT_EQ(PrimeNumbers<unsigned>::nthPrime(9), 29);
    EXPECT_EQ(PrimeNumbers<unsigned>::nthPrime(900), 7001);
    EXPECT_EQ(PrimeNumbers<unsigned>::nthPrime(9000), 93187);

}

TEST(TestNumberTheory, CollatzSeq) {
    using snapsnip::CollatzSeq;
    CollatzSeq<unsigned> coll1(17);
    EXPECT_EQ(coll1.getSequence().size(), 13);
    CollatzSeq<unsigned> coll2(6003);
    EXPECT_EQ(coll2.getSequence().size(), 42);
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

TEST(TestNumberTheory, Factorization) {
    using snapsnip::Factors;
    Factors<long> f(130);
    EXPECT_TRUE(true);
}