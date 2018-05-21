#include <math.h>
#include <iostream>

#include "Primes.hpp"

typedef unsigned long ul;

ul countDivisors(ul n, ma::Sieve<ul>& sieve) {
    ul divisors = 1; // Include 1 and self
    ul p_index = 0;
    unsigned result = 1;
    unsigned p = sieve.getNthPrime(p_index);

    while (p <= n) {
        ul p_div = 0;
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
    ma::Sieve<ul> sieve(1000000);

    ul max_n = 16;
    ul max_n_so_far = 0;
    for (ul n = 2; n <= max_n; n++) {
        //std::cout << "Solutions for n = " << n << std::endl;
        const ul ns = n * n;
        // std::cout << "  (x, y) = (" << n + 1 << ", " << n + ns << ")" << std::endl;
        // std::cout << "  (x, y) = (" << n + n << ", " << n + n << ")" << std::endl;
        ul numSolutionsForN = 2;
        for (ul k = 2; k < n; k++) {
            if (ns % k == 0) {
                ++numSolutionsForN;
                //const ul y = n + ns / k;
                //const ul x = n + (ns * k) / ns;
                // std::cout << "  (x, y) = (" << x << ", " << y << ")" << std::endl;
            }
        }
        //if (numSolutionsForN > max_n_so_far) {
            std::cout << "S(" << n << ") = " << numSolutionsForN << std::endl;
            max_n_so_far = numSolutionsForN;
        //}
    }

    return 0;
}