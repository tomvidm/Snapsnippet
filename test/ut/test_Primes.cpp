#include "gtest/gtest.h"

#include "Primes.hpp"

TEST(TestPrimes, SieveConstructor) {
    using namespace ma;

    Sieve<int> sieve(100000);

    EXPECT_EQ(isPrime(0, sieve), 0);
    EXPECT_EQ(isPrime(1, sieve), 0);
    EXPECT_EQ(isPrime(2, sieve), 1);
    EXPECT_EQ(isPrime(3, sieve), 1);
    EXPECT_EQ(isPrime(4, sieve), 0);
    EXPECT_EQ(isPrime(5, sieve), 1);
    EXPECT_EQ(isPrime(6, sieve), 0);
    EXPECT_EQ(isPrime(7, sieve), 1);
    EXPECT_EQ(isPrime(997, sieve), 1);


    EXPECT_EQ(nextPrime(2, sieve), 3);
    EXPECT_EQ(nextPrime(3, sieve), 5);
    EXPECT_EQ(nextPrime(7, sieve), 11);
    EXPECT_EQ(nextPrime(8, sieve), 11);

    EXPECT_EQ(sieve.getNthPrime(0), 2);
    EXPECT_EQ(sieve.getNthPrime(1), 3);
    EXPECT_EQ(sieve.getNthPrime(2), 5);
    EXPECT_EQ(sieve.getNthPrime(3), 7);
}