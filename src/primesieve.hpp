#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

#include "numbertheory.hpp"

namespace snapsnip {
    template <typename T>
    std::vector<T> sievePrimes_optimized(const size_t lim) {
        if (lim < 2) {
            return std::vector<T>();
        } else if (lim == 2) {
            return std::vector<T>{2};
        } else if (lim == 3) {
            return std::vector<T>{2, 3};
        }

        std::vector<T> result = {2};
        const double limd = static_cast<double>(lim);
        const size_t numPrimesUpperBound = static_cast<size_t>(1 + limd / log(limd));
        if (lim > 10000) {
            result.reserve(numPrimesUpperBound);
        }

        std::vector<bool> boolmap(lim + 1, true);
        for (size_t i = 2; i <= lim; i += 2) {
            boolmap[i] = false;
        }

        const size_t sqrtLim = intSqrt(lim);
        for (size_t i = 3; i <= sqrtLim; i += 2) {
            if (!boolmap[i]) {
                continue;
            }  else {
                for (size_t k = 2 * i; k + i <= lim; k += i) {
                    boolmap[k] = false;
                }
            }
        }

        for (size_t i = 3; i < lim; i += 2) {
            if (boolmap[i]) {
                result.push_back(static_cast<T>(i));
            }
        }

        return result;
    }


    template <unsigned N>
    std::array<bool, N> sievePrimes_boolmap() {
        std::array<bool, N> boolmap;
        boolmap.fill(true);
        boolmap[0] = false;
        boolmap[1] = false;
        for (size_t i = 4; i <= N; i += 2) {
            boolmap[i] = false;
        }

        const size_t sqrtLim = intSqrt(N);
        for (size_t i = 3; i <= sqrtLim; i += 2) {
            if (!boolmap[i]) {
                continue;
            }  else {
                for (size_t k = 2 * i; k + i <= N; k += i) {
                    boolmap[k] = false;
                }
            }
        }
        
        return boolmap;
    }

    template <typename T, unsigned N>
    bool isPrime_lookup(const T p) {
        static const std::array<bool, N> boolmap = sievePrimes_boolmap<N>();
        return boolmap[p];
    }


    template <typename T>
    std::vector<T> sievePrimes_naive(const size_t lim) {
        if (lim < 2) {
            return std::vector<T>();
        } else if (lim == 2) {
            return std::vector<T>{2};
        } else if (lim == 3) {
            return std::vector<T>{2, 3};
        } else {
            std::vector<T> result = {2};
            std::vector<bool> boolmap(lim + 1, true);

            for (size_t i = 2; i <= lim; i += 2) {
                boolmap[i] = false;
            }

            size_t i = 3;
            //std::cout << "lim = " << lim << std::endl;
            while (i <= lim) {
            //std::cout << "i = " << i << std::endl;
                size_t k = 2 * i;
                while (k <= lim - i) {
                    k += i;
                    boolmap[k] = false;
                }
                /* do {
                } while (2 * k <= lim); */

                result.push_back(i);

                do {
                    i += 2;
                } while (!boolmap[i]);
            }
            return result;
        }
    }
}