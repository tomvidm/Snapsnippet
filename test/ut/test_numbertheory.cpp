#include "gtest/gtest.h"
#include <iostream>
#include <limits>
#include "numbertheory.hpp"
#include "primesieve.hpp"
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

TEST(TestNumberTheory, CollatzSeq) {
    using snapsnip::CollatzSeq;
    CollatzSeq<unsigned> coll1(17);
    EXPECT_EQ(coll1.getSequence().size(), 13);
    CollatzSeq<unsigned> coll2(6003);
    EXPECT_EQ(coll2.getSequence().size(), 42);
}

TEST(TestNumberTheory, test_previousPrime) {
    using namespace snapsnip;
    
    EXPECT_EQ(previousPrime(250), 241);
    EXPECT_EQ(previousPrime(241), 239);
    EXPECT_EQ(previousPrime(239), 233);
}

TEST(TestNumberTheory, ModExp) {
    using snapsnip::modexp;
    EXPECT_EQ(modexp<unsigned long>(0, 0, 0), 1);
    EXPECT_EQ(modexp<unsigned long>(0, 1, 0), 0);
    EXPECT_EQ(modexp<unsigned long>(1, 0, 0), 1);
    EXPECT_EQ(modexp<unsigned long>(1, 1, 0), 1);

    EXPECT_EQ(modexp<unsigned long>(5, 2, 0), 25);
    EXPECT_EQ(modexp<unsigned long>(5, 2, 10), 5);
    EXPECT_EQ(modexp<unsigned long>(5, 2, 5), 0);
 
    EXPECT_EQ(modexp<unsigned long>(234, 24144, 231445), 143141);
    EXPECT_EQ(modexp<unsigned long>(32234, 2427144, 23144523), 9958798);
}

TEST(TestNumberTheory, test_isPrime) {
    using snapsnip::isPrime;

    EXPECT_TRUE(isPrime(2));
    EXPECT_TRUE(isPrime(3));
    EXPECT_TRUE(isPrime(5));
    EXPECT_TRUE(isPrime(7));
    EXPECT_TRUE(isPrime(11));
    EXPECT_TRUE(isPrime(13));
    
    EXPECT_FALSE(isPrime(4));
    EXPECT_FALSE(isPrime(6));
    EXPECT_FALSE(isPrime(9));
    EXPECT_FALSE(isPrime(15));

    EXPECT_TRUE(isPrime(10001533));
    EXPECT_TRUE(isPrime(1000000901));
    EXPECT_TRUE(isPrime(1424201617));
    EXPECT_TRUE(isPrime(1832201143));
    EXPECT_TRUE(isPrime(10832201147));
    EXPECT_FALSE(isPrime(10832201149));
    EXPECT_TRUE(isPrime(10832201153));
    EXPECT_FALSE(isPrime(10832201157));
    EXPECT_TRUE(isPrime(120832204817));
}

TEST(TestNumberTheory, test_nextPrime) {
    using snapsnip::nextPrime;
    EXPECT_EQ(nextPrime(2), 3);
    EXPECT_EQ(nextPrime(3), 5);
    EXPECT_EQ(nextPrime(5), 7);
    EXPECT_EQ(nextPrime(7), 11);
}

TEST(TestNumberTheory, test_primeFactorization) {
    using namespace snapsnip;

    std::vector<PrimeFactor<long>> pf = primeFactorization<long>(90);
    std::vector<PrimeFactor<long>> pf_expected = {{2, 1}, {3, 2}, {5, 1}};
    EXPECT_EQ(pf, pf_expected);

    std::vector<PrimeFactor<long>> pf2 = primeFactorization<long>(141);
    std::vector<PrimeFactor<long>> pf2_expected = {{3, 1}, {47, 1}};
    EXPECT_EQ(pf2, pf2_expected);

    std::vector<PrimeFactor<long>> pf3 = primeFactorization<long>(10000);
    std::vector<PrimeFactor<long>> pf3_expected = {{2, 4}, {5, 4}};
    EXPECT_EQ(pf3, pf3_expected);
}

TEST(TestNumberTheory, test_totientFunction) {
    using namespace snapsnip;

    EXPECT_EQ(eulerTotient(101), 100);
    EXPECT_EQ(eulerTotient(140), 48);
    EXPECT_EQ(eulerTotient(141), 92);
    EXPECT_EQ(eulerTotient(149), 148);
    EXPECT_EQ(eulerTotient(10000), 4000);
    EXPECT_EQ(eulerTotient(123123), 57600);
    EXPECT_EQ(eulerTotient(123123123), 80079840);
    EXPECT_EQ(eulerTotient(987987987987), 459043200000);
}

TEST(TestNumberTheory, test_fermatPrimality) {
    using namespace snapsnip;

    EXPECT_TRUE(isPrime<unsigned long>(140003081));
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

TEST(TestNumberTheory, test_intSqrt) {
    using namespace snapsnip;
    EXPECT_EQ(intSqrt(36), 6);
    EXPECT_EQ(intSqrt(35), 5);
    EXPECT_EQ(intSqrt(34), 5);
    EXPECT_EQ(intSqrt(33), 5);
    EXPECT_EQ(intSqrt(32), 5);
    EXPECT_EQ(intSqrt(31), 5);
    EXPECT_EQ(intSqrt(30), 5);
    EXPECT_EQ(intSqrt(29), 5);
    EXPECT_EQ(intSqrt(28), 5);
    EXPECT_EQ(intSqrt(27), 5);
    EXPECT_EQ(intSqrt(26), 5);
    EXPECT_EQ(intSqrt(25), 5);
    EXPECT_EQ(intSqrt(24), 4);
}

TEST(TestNumberTheory, test_primeSieve) {
    using namespace snapsnip;

    std::vector<int> ps1 = sievePrimes_optimized<int>(2);
    std::vector<int> ps1_e = {2};
    std::vector<int> ps2 = sievePrimes_optimized<int>(3);
    std::vector<int> ps2_e = {2, 3};
    std::vector<int> ps3a = sievePrimes_optimized<int>(30);
    std::vector<int> ps3b = sievePrimes_optimized<int>(30);
    std::vector<int> ps3_e = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

    EXPECT_EQ(ps1, ps1_e);
    EXPECT_EQ(ps2, ps2_e);
    EXPECT_EQ(ps3a, ps3_e);
    EXPECT_EQ(ps3b, ps3_e);

    std::array<bool, 15> bm1 = sievePrimes_boolmap<15>();
    std::array<bool, 15> bm1_e = std::array<bool, 15>{
        0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0
    };
    EXPECT_EQ(bm1, bm1_e);

    bool isit = isPrime_lookup<size_t, 15>(2);
    EXPECT_TRUE(isit);
    isit = isPrime_lookup<size_t, 15>(3);
    EXPECT_TRUE(isit);
    isit = isPrime_lookup<size_t, 15>(4);
    EXPECT_FALSE(isit);
    isit = isPrime_lookup<size_t, 15>(7);
    EXPECT_TRUE(isit);
}