#pragma once

namespace snapsnip {
    template <typename T>
    T modPow(T base, T exp, T mod) {
        if (mod == 0) {
            return 0;
        } else {
            T c = 1;
            for (T e = 1; e <= exp; e++) {
                c = (c * base) % mod;
            }
            return c;
        }
    }
}