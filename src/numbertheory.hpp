#pragma once

#include <vector>
#include <map>
#include <algorithm>

namespace snapsnip {
    /*
        Divisibility
    */

    template <typename T>
    bool isDivisiblyBy(T n, T d) {
        return (n % d == 0) ? true : false;
    } // isDibisbleBy

    /*
        Common divisor
    */

    template <typename T>
    T findCommonDivisor(T a, T b) {
        for (T i = std::max<T>(a, b)/2; i >= 2; --i) {
            if ((a % i == 0) && (b % i == 0)) {
                return i;
            }
        }
        return 1;
    }

    /*
        This class encapsulates the fibonacci sequence by providing a simple interface
        for getting the nth fibonacci number while also storing them in an array
        for quick retrieval later.
    */

    template <typename T>
    class FibonacciSeq {
    public:
        static T nthElement(unsigned n);
        static void resize(unsigned L);
    private:
        static std::vector<T> sequence;
    }; // FibonacciSeq

    template <typename T>
    T FibonacciSeq<T>::nthElement(unsigned n) {
        resize(n);
        return sequence[n];
    } // nthElement

    template <typename T>
    void FibonacciSeq<T>::resize(unsigned L) {
        unsigned k = sequence.size();
        while (k <= L) {
            sequence.push_back( sequence[k - 1] + sequence[k - 2] );
            ++k;
        } // if
    } // resize

    template <typename T>
    std::vector<T> FibonacciSeq<T>::sequence = {0, 1};

    /*
        This class encapsulates a generalized fibonacci sequence with arbitrary
        number of seed values.
    */

    template <typename T>
    class PrimeNumbers {
    public:
        static void resize(unsigned L);
        static T nthPrime(unsigned n);
        static T nextPrime();
        static bool isPrime(const T& candidate);
        static void generateUntil(const T& candidate);
    private:
        static std::vector<T> sequence;
    }; // class PrimeNumbers

    template <typename T>
    T PrimeNumbers<T>::nthPrime(unsigned n) {
        resize(n);
        return sequence[n];
    } // nthPrime

    template <typename T>
    bool PrimeNumbers<T>::isPrime(const T& candidate) {
        for (auto p : sequence) {
            if (isDivisiblyBy<T>(candidate, p)) {
                return false;
            } // if
        } // for
        return true;
    } // isPrime

    template <typename T>
    void PrimeNumbers<T>::resize(unsigned L) {
        unsigned k = sequence.size();
        while (k <= L) {
            sequence.push_back(nextPrime());
            ++k;
        } // if
    } // resize

    template <typename T>
    T PrimeNumbers<T>::nextPrime() {
        T nextPrimeCandidate = sequence.back() + 2;
        while (!isPrime(nextPrimeCandidate)) {
            nextPrimeCandidate += 2;
        } // while
        return nextPrimeCandidate;
    }  // nextPrime

    template <typename T>
    std::vector<T> PrimeNumbers<T>::sequence = {2, 3};

    /* 
        Collatz sequence
    */

    template <typename T>
    class CollatzSeq {
    public:
        CollatzSeq(T k);
        void build(T k);
        const std::vector<T>& getSequence() const;
        typename std::vector<T>::const_iterator cbegin() const;
        typename std::vector<T>::const_iterator cend() const;
    private:
        std::vector<T> sequence;
        std::map<unsigned, T> map;
    }; // CollatzSeq
    template <typename T>
    CollatzSeq<T>::CollatzSeq(T k) {
        build(k);
    } // constructor

    template <typename T>
    void CollatzSeq<T>::build(T k) {
        sequence.clear();
        sequence.push_back(k);
        map[k] = sequence.size() - 1;
        while (k != 1) {
            if (isDivisiblyBy<T>(k, 2)) {
                k /= 2;
                sequence.push_back(k);
                map[k] = sequence.size() - 1;
            } else {
                k *= 3;
                k += 1;
                sequence.push_back(k);
                map[k] = sequence.size() - 1;
            } // if else
        } // while
    } // build

    template <typename T>
    const std::vector<T>& CollatzSeq<T>::getSequence() const {
        return sequence;
    } // getSequence

    template <typename T>
    typename std::vector<T>::const_iterator CollatzSeq<T>::cbegin() const {
        return sequence.cbegin();
    } // getSequence

    template <typename T>
    typename std::vector<T>::const_iterator CollatzSeq<T>::cend() const {
        return sequence.cend();
    } // getSequence

    /*
        Exponentiation
    */

    template <typename T>
    T iexp(T base, T exp) {
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

    template <typename T>
    T modexp(T base, T exp, T mod) {
        if (mod == 0) {
            return iexp<T>(base, exp);
        } else {
            T result = 1;
            while (exp) {
                if (exp & 1) {
                    result *= base;
                    base %= mod;
                }
                exp >>= 1;
                base *= base;
                base %= mod;
            }
            return result;
        }
    }

    /* 
        Hyperexponentiation
    */

    template <typename T>
    T hyperexp(T base, T hypexp, T mod) {
        if (hypexp == 1) {
            return base % mod;
        } else {
            return modexp(base, hyperexp(base, hypexp - 1, mod), mod);
        }
    }

    /*
        Factorization
    */

    template <typename T>
    class Factors {
    public:
        Factors(T n);
    private:
        const T base;
        std::vector<T> factors = {1};
    }; // class Factors

    template <typename T>
    Factors<T>::Factors(T n) 
    : base(n) {
        for (T d = 2; d < n; d++) {
            while (isDivisiblyBy(n, d)) {
                n /= d;
                factors.push_back(d);
            } // if
        } // for
    } // constructor
    
} // namespace snapsnip