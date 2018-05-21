#include "numbertheory.hpp"

#include <iostream>
#include <unordered_map>
#include <map>
#include <array>
#include <time.h>

#include "EulerTotient.hpp"
#include "Primes.hpp"


int main() {
    using ulong = unsigned long;

    const size_t N = 100;

    std::vector<ulong> phiList(N + 1, 0);
    std::vector<ulong> length(N + 1);
    std::vector<bool> isprime(N + 1, false);
    phiList[1] = 1;
    for (size_t i = 2; i <= N; i++) {
        if (!phiList[i]) {
            phiList[i] = i - 1;
            isprime[i] = true;
        }

        for (size_t k = 2 * i; k <= N; k += i) {
            if (!phiList[k]) phiList[k] = k;
            phiList[k] = (i - 1) * phiList[k] / i;

        }
        length[i] = length[phiList[i]] + 1;
    }

    size_t numSols = 0;
    size_t sum = 0;
    for (size_t i = 2; i < phiList.size(); i++) {
        std::cout << i << " ";
        size_t k = i;
        while (k > 1) {
            k = phiList[k];
            std::cout << k << " ";
        }
        std::cout << std::endl;
    }

    std::cout << numSols << std::endl;
    std::cout << sum << std::endl;

    return 0;
}