#pragma once

namespace snapsnip {

    /*
        Calculating the combinations of n choose k normally requires
        computing factorials which will quickly overflow without 
        arbitrary precision numbers. This algorithm circumvents this (reduces risk)
        by ignoring the terms that cancel eachother. 
    */
    template <typename T>
    T combinations(T n, T k) {
        if (n == k) { 
            return 1; 
        } else if (k == 0 || n < k) {
            return 0;
        } else {
            T result = n;
            T d = 1;
            while (--n > k) {
                result *= n;
                result /= ++d;
            } // while
            return result;
        } // if else
    } // combinations
} // namespace snapsnip