#pragma once

namespace snapsnip {
    template <typename T>
    class BinaryTreeIndexed {
    public:
        static unsigned parent(const unsigned& n) const;
        static unsigned left(const unsigned& n) const;
        static unsigned right(const unsigned& n) const;
    private:
        std::vector<T> tree;
    }; // BinaryTree

    template <typename T>
    unsigned BinaryTree::left(const unsigned& n) const {
        return (n - 1)/2;
    } // left

    template <typename T>
    unsigned BinaryTree::left(const unsigned& n) const {
        return 2*n + 1;
    } // left

    template <typename T>
    unsigned BinaryTree::right(const unsigned& n) const {
        return 2*n + 2;
    } // left
} // namespace snapsnip