#pragma once

#include "numbertheory.hpp"
#include "primesieve.hpp"

namespace snapsnip {
    typedef size_t uint;

    // The template parameter sets a bound on the size of the prime
    // lookup table that will be generated.

    template <uint N>
    bool isPrime_c(const uint c) {
        return isPrime_lookup<uint, N>(c);
    }

    template <uint N>
    uint nextPrime_c(uint x) {
        do {
            ++x;
        } while (!isPrime_c<N>(x));

        return x;
    }

    template <uint N>
    uint eulerTotient_c(uint x) {
        if (isPrime_c<N>(x)) {
            return x - 1;
        } else {
            uint p = 2;
            uint result = 1;
            for (uint p = 2; p <= x; p = nextPrime_c<N>(p)) {
                uint mult = 0;
                while (x % p == 0) {
                    x /= p;
                    ++mult;
                }

                if (mult > 0) {
                    result *= iexp(p, mult - 1) * (p - 1);
                }
            }
            return result;
        }
    }
}