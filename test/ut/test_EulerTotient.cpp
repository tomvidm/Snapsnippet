#include "gtest/gtest.h"

#include "Primes.hpp"
#include "EulerTotient.hpp"

TEST(TestModularArithmetic, EulerTotient) {
    using namespace ma;

    Sieve<int> sieve(10000);

    EXPECT_EQ(eulerPhi(2, sieve), 1);
    EXPECT_EQ(eulerPhi(3, sieve), 2);
    EXPECT_EQ(eulerPhi(4, sieve), 2);
    EXPECT_EQ(eulerPhi(5, sieve), 4);
    EXPECT_EQ(eulerPhi(6, sieve), 2);
    EXPECT_EQ(eulerPhi(7, sieve), 6);
    EXPECT_EQ(eulerPhi(8, sieve), 4);
    EXPECT_EQ(eulerPhi(9, sieve), 6);
    EXPECT_EQ(eulerPhi(10, sieve), 4);
    EXPECT_EQ(eulerPhi(11, sieve), 10);
    EXPECT_EQ(eulerPhi(12, sieve), 4);
}