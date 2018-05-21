# Symbolic mathematical expressions
How to implement it?
## Fictional API
I want to generate a data structure the expression `x^2 + y^2 = 1` in a form that lets me automatically solve for y. I should be able to constuct it from the string `"x^2 + y^2 = 1"`. Parsing from a string can be ignored for now, and expressions such as `x^2` should be manually constructed.

The smallest part of an expression should be:

1. Constants
2. Variables
3. Operators (unary and binary)
4. Expression
