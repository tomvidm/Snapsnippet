#include <iostream>

#include "Primes.hpp"
#include "EulerTotient.hpp"

template <typename T>
T gcd(T a, T b) {
    while (b != 0) {
        const T t = b;
        b = a % b;
        a = t;
    } return a;
}

long tri(long n) {
    return ( n * (n + 1))/2;
}

size_t countDivisors(long n, ma::Sieve<long>& sieve) {
    size_t divisors = 1; // Include 1 and self
    size_t p_index = 0;
    unsigned result = 1;
    unsigned p = sieve.getNthPrime(p_index);

    while (p <= n) {
        size_t p_div = 0;
        while (n % p == 0) {
            n /= p;
            ++p_div;
        }
        divisors *= (p_div + 1);
        p = sieve.getNthPrime(++p_index);
    }
    return divisors;
}

int main() {
    long P = 10000000;
    long N = 20000;

    // Set up prime sieve for fast calculation of euler totient (Well, not faster than direct sieving)
    ma::Sieve<long> sieve(P);

    long maxNumDiv = 0;
    for (long i = 2; i < N; i += 1) {
        long n = tri(i);
        long divisorSum = countDivisors(n, sieve);
        if (divisorSum > maxNumDiv) {
            std::cout << i << "\t" << n << "\t" << divisorSum << std::endl;
            maxNumDiv = divisorSum;

        }
/* 
        std::cout << "i = " << i << "\tphi(" << (i * (i + 1)) / 2 << ") = " << ma::eulerPhi(a, sieve) * ma::eulerPhi(b, sieve) << std::endl;
        std::cout << "i = " << i + 1 << "\tphi(" << ((i + 1) * (i + 2)) / 2 << ") = " << ma::eulerPhi(x, sieve) * ma::eulerPhi(y, sieve) << std::endl; */
    }
}