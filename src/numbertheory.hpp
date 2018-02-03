#pragma once

#include <vector>
#include <map>

namespace snapsnip {

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
        if (k <= L) {
            sequence.push_back( sequence[k - 1] + sequence[k - 2] );
            ++k;
        } // if
    } // resize

    template <typename T>
    std::vector<T> FibonacciSeq<T>::sequence = {0, 1};

    /* 
        Collatz sequence
    */

    template <typename T>
    class CollatzSeq {
    public:
        CollatzSeq::CollatzSeq(T k);
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
            if (k % 2 == 0) {
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
    
} // namespace snapsnip