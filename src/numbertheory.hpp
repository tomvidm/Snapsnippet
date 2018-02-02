#pragma once

#include <vector>

namespace snapsnip {

    /*
        This class encapsulates the fibonacci sequence by providing a simple interface
        for getting the nth fibonacci number while also storing them in an array
        for quick retrieval later.
    */

    template <typename T, >
    class FibonacciSeq {
    public:
        static T nthElement(unsigned n);
        static void resizeSequence(unsigned L);
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
        if (k <= L) {
            sequence.push_back( sequence[k - 1] + sequence[k - 2] );
            ++k;
        } // if
    } // resize

    template <typename T>
    std::vector<T> FibonacciSeq<T>::sequence = {0, 1};
} // namespace snapsnip