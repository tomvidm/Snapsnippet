#include "gtest/gtest.h"

#include "numbertheory2.hpp"

TEST(TestNumberTheory2, isPrime) {
    using namespace snapsnip;

    EXPECT_TRUE(isPrime_c<1500000>(149));
    EXPECT_TRUE(isPrime_c<1500000>(7));
    EXPECT_TRUE(isPrime_c<1500000>(997));
    EXPECT_FALSE(isPrime_c<1500000>(992));
}

TEST(TestNumberTheory2, nextPrime) {
    using namespace snapsnip;

    EXPECT_EQ(nextPrime_c<150000>(5), 7);
    EXPECT_EQ(nextPrime_c<150000>(15), 17);
    EXPECT_EQ(nextPrime_c<150000>(16), 17);
}

TEST(TestNumberTheory2, test_totientFunction) {
    using namespace snapsnip;

    EXPECT_EQ(eulerTotient_c<150000>(101), 100);
    EXPECT_EQ(eulerTotient_c<150000>(140), 48);
    EXPECT_EQ(eulerTotient_c<150000>(141), 92);
    EXPECT_EQ(eulerTotient_c<150000>(149), 148);
    EXPECT_EQ(eulerTotient_c<150000>(10000), 4000);
    EXPECT_EQ(eulerTotient_c<150000>(123123), 57600);

}
