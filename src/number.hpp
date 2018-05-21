#pragma once

#include <array>

namespace snapsnip {
    template <typename T, unsigned N>
    struct Number {
        Number(const T number, const std::array<T, N>& mods);
        Number(const std::array<T, N>& mods);
        T number;
        std::array<T, N> data;
        std::array<T, N> moduli;
    };

    template <typename T, unsigned N>
    Number<T, N>::Number(const T number, const std::array<T, N>& mods)
    : number(number), moduli(mods) {
        for (size_t i = 0; i < mods.size(); i++) {
            data[i] = number % moduli[i];
        }
    }

    template <typename T, unsigned N>
    Number<T, N>::Number(const std::array<T, N>& mods)
    : moduli(mods) {
        ;
    }

    template <typename T, unsigned N>
    const Number<T, N> operator + (const Number<T, N>& lhs, const Number<T, N>& rhs) {
        return Number<T, N>(lhs.number + rhs.number, lhs.moduli);
    }

    template <typename T, unsigned N>
    const Number<T, N> operator * (const Number<T, N>& lhs, const Number<T, N>& rhs) {
        return Number<T, N>(lhs.number * rhs.number, lhs.moduli);
    }
}