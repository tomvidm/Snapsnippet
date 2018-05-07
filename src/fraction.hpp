#pragma once

#include "numbertheory.hpp"

namespace snapsnip {
    template <typename T>
    class Fraction {
    public:
        Fraction();
        Fraction(T n);
        Fraction(T n, T d);
        Fraction(const Fraction<T>& cp);
        Fraction(const Fraction<T>&& mv);

        void reduce();

        bool operator == (const Fraction<T>& rhs) const;
        bool operator < (const Fraction<T>& rhs) const;
        bool operator > (const Fraction<T>& rhs) const;

        Fraction<T> operator + (const Fraction<T>& rhs) const;
        // Fraction<T> operator - (const Fraction<T>& cp);
        Fraction<T> operator * (const Fraction<T>& rhs) const;
        Fraction<T> operator / (const Fraction<T>& rhs) const;

        inline T getNumerator() const { return numerator; }
        inline T getDenominator() const { return denominator; }
    protected:
        T numerator;
        T denominator;
    }; // Fraction

    template <typename T>
    Fraction<T>::Fraction()
    : numerator(0), denominator(0) {
        ;
    }

    template <typename T>
    Fraction<T>::Fraction(T n)
    : numerator(n), denominator(1) {
        ;
    }

    template <typename T>
    Fraction<T>::Fraction(T n, T d)
    : numerator(n), denominator(d) {
        ;
    }

    template <typename T>
    void Fraction<T>::reduce() {
        T divisor;
        do {
            divisor = gcd_iterative<T>(numerator, denominator);
            numerator /= divisor;
            denominator /= divisor;
        } while (divisor > T(1));
    }

    template <typename T>
    Fraction<T>::Fraction(const Fraction<T>& cp)
    : numerator(cp.numerator), denominator(cp.denominator) {
        ;
    }

    template <typename T>
    Fraction<T>::Fraction(const Fraction<T>&& mv)
    : numerator(mv.numerator), denominator(mv.denominator) {
        ;
    }

    template <typename T>
    bool Fraction<T>::operator == (const Fraction<T>& rhs) const {
        return (getNumerator() == rhs.getNumerator()) && (getDenominator() == rhs.getDenominator());
    }

    template <typename T>
    bool Fraction<T>::operator < (const Fraction<T>& rhs) const {
        return (getNumerator() * rhs.getDenominator() < getDenominator() * rhs.getNumerator());
    }

    template <typename T>
    bool Fraction<T>::operator > (const Fraction<T>& rhs) const {
        return (getNumerator() * rhs.getDenominator() > getDenominator() * rhs.getNumerator());
    }

    template <typename T>
    Fraction<T> Fraction<T>::operator + (const Fraction<T>& rhs) const {
        Fraction<T> temp(getNumerator() * rhs.getDenominator() + getDenominator() * rhs.getNumerator(),
                         getDenominator() * rhs.getDenominator());
        temp.reduce();
        return temp;
    }

    template <typename T>
    Fraction<T> Fraction<T>::operator * (const Fraction<T>& rhs) const {
        Fraction<T> temp(getNumerator() * rhs.getNumerator(),
                         getDenominator() * rhs.getDenominator());
        temp.reduce();
        return temp;
    }

    template <typename T>
    Fraction<T> Fraction<T>::operator / (const Fraction<T>& rhs) const {
        Fraction<T> temp(getNumerator() * rhs.getDenominator(),
                         getDenominator() * rhs.getNumerator());
        temp.reduce();
        return temp;
    }
}