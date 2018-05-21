#pragma once

namespace ma {
    template <typename T>
    size_t findIndexOf(const T target, const std::vector<T>& sortedList, const size_t lower, const size_t upper) {
        if (sortedList[lower] == target) return lower;
        if (sortedList[upper] == target) return upper;
        
        size_t mid = (lower + upper) / 2;
        if (sortedList[mid] < target) {
            return findIndexOf(target, sortedList, mid, upper);
        } else {
            return findIndexOf(target, sortedList, lower, mid);
        }
    }

    template <typename T>
    size_t findIndexOf(const T target, const std::vector<T>& sortedList) {
        size_t lower = 0;
        size_t upper = sortedList.size() - 1;

        return findIndexOf(target, sortedList, lower, upper);
    }
}