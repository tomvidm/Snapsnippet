#pragma once

#include <math.h>
#include <algorithm>
#include <vector>

#include "Primes.hpp"
#include "ModularArithmetic.hpp"

namespace ma {
    template <typename T>
    T eulerPhi(const T n, Sieve<T>& sieve) {
        if (isPrime(n, sieve)) {
            return n - 1;
        } else {
            size_t p_index = 0;
            T result = 1;
            T x = n;
            T p = sieve.getNthPrime(p_index);

            while (p <= x) {
                T multiplicity = 0;
                while (x % p == 0) {
                    x /= p;
                    ++multiplicity;
                }
                if (multiplicity > 0) {
                    result *= iPow(p, multiplicity - 1) * (p - 1);
                }
                p = sieve.getNthPrime(++p_index);
            }
            return result;
        }
    }

    template <typename T>
    std::vector<T> sieveEulerPhi(const size_t upperLim) {
        std::vector<T> phiList(upperLim + 1, 0);
        phiList[1] = 1;
        for (size_t i = 2; i <= upperLim; i++) {
            if (!phiList[i]) phiList[i] = i - 1;
            for (size_t k = 2 * i; k <= upperLim; k += i) {
                if (!phiList[k]) phiList[k] = k;
                phiList[k] = (i - 1) * phiList[k] / i;
            }
        }
    }
}