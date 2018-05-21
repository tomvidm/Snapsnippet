#pragma once

namespace ma {
    template <typename T>
    T iPow(T base, T exp) {
        T result = 1;
        while (exp > 0) {
            if (exp & 1) {
                result *= base;
            }
            exp >>= 1;
            base *= base;
        }
        return result;
    }
}