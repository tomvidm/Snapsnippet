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
        if (n == k) {                   // Equals 1 by definition
            return 1; 
        } else if (k == 0 || n < k) {   // Equals 0 by definition??
            return 0;
        } else {                        // Proceed with calculation
            T result = n;               // Start with highest multiplier
            T d = 1;                    // Keep track of lower multipliers
            while (--n > k) {           // Keep going until n == k
                result *= n;            // multiply numerator term
                result /= ++d;          // divide denominator term
            } // while
            return result;              // return
        } // if else
    } // combinations
} // namespace snapsnip