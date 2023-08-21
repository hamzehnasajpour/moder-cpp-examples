/*
In the main() function, we use constexpr to define an integer n and calculate the factorial 
of n using the factorial function. Since the value of n is known at compile time, the entire 
computation is performed during compilation, and the result is embedded directly into the 
compiled code.

Benefits of using constexpr:

Compile-time evaluation: 
    The factorial function is evaluated at compile time, avoiding runtime computation overhead.
Potential performance improvement: 
    The computed value is known at compile time, which might lead to optimized code.
Compile-time errors: 
    If a constexpr computation encounters issues that cannot be resolved at compile time, the compiler will generate errors, helping catch issues early in the development process.
*/
#include <iostream>

constexpr int factorial(int n) {
    return (n <= 1) ? 1 : n * factorial(n - 1);
}

int main() {
    constexpr int n = 5;
    constexpr int result = factorial(n);

    std::cout << "Factorial of " << n << " is " << result << std::endl;  // Output: Factorial of 5 is 120

    return 0;
}
