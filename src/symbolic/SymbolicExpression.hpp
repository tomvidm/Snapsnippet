#include <memory>

namespace snapsnip { namespace symmath {
    template <typename T>
    class SymbolicExpression {
    public:
        enum class Type {
            Variable,
            Constant,
            Addition,
            Subtraction,
            Multiplication,
            Division,
            Exponentiation
        };

    private:
        std::string key;
        std::unique_ptr<SymbolicExpression<T>> lhs;
        std::unique_ptr<SymbolicExpression<T>> rhs;
    }; // class SymbolicExpression
} // namespace symbolic
} // namespace snapsnip