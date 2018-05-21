#pragma once

#include <math.h>
#include <algorithm>
#include <vector>

namespace ma {
    template <typename T>
    class Sieve {
    public:
        Sieve(const T upperLim);

        const bool get(const size_t x) const;
        const T getNthPrime(const size_t n) const;
    private:
        void reconstruct(const size_t x);
        void constructPrimes();
        std::vector<bool> bitmask;
        std::vector<T> primes;
    }; // class Sieve

    template <typename T>
    Sieve<T>::Sieve(const T upperLim) {
        std::cout << "Sieving primes...\n";
        reconstruct(upperLim);
        std::cout << "Extracting primes from sieve...\n";
        constructPrimes();
        std::cout << "FINISH!\n";
    }

    template <typename T>
    void Sieve<T>::reconstruct(const size_t x) {
        bitmask.assign(std::max(x, static_cast<size_t>(2)) + 1, true);

        // 0 and 1 are not prime
        bitmask[0] = false;
        bitmask[1] = false;

        // Get the floor of the square root of x
        const size_t sqrtOfSoftLimit = floor(static_cast<size_t>(sqrt(static_cast<double>(x))));

        // All even numbers > 2 are not prime
        for (size_t i = 4; i < bitmask.size(); i += 2) {
            bitmask[i] = false;
        }

        for (size_t i = 3; i <= sqrtOfSoftLimit; i += 2) {
            for (size_t k = 2 * i; k < bitmask.size(); k += i) {
                bitmask[k] = false;
            }
        }
    }

    template <typename T>
    void Sieve<T>::constructPrimes() {
        const double limd = static_cast<double>(bitmask.size());
        if (limd > 10000.0) {
            const size_t upperBound = static_cast<size_t>(1.15 * limd / log(limd));
            primes.reserve(upperBound);
        } else {
            primes.reserve(10000);
        }

        primes.push_back(2);
        for (size_t i = 3; i < bitmask.size(); i += 2) {
            if (bitmask[i]) {
                primes.push_back(i);
            }
        }
    }

    template <typename T>
    const bool Sieve<T>::get(const size_t x) const {
        return bitmask[x];
    }

    template <typename T>
    const T Sieve<T>::getNthPrime(const size_t n) const {
        return primes[n];
    }

    // Methods that use Sieve class

    template <typename T>
    bool isPrime(const size_t x, Sieve<T>& sieve) {
        return sieve.get(x);
    }

    template <typename T>
    T nextPrime(T p, Sieve<T>& sieve) {
        if (p == 2) return 3;
        if (p % 2 == 0) ++p;
        while (!sieve.get(p += 2));
        return p;
    }

}