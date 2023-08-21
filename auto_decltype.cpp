#include <iostream>

int main() {
    // Using auto to deduce the type of a variable
    auto number = 42;  // The type of 'number' will be deduced as int
    auto pi = 3.14159; // The type of 'pi' will be deduced as double

    std::cout << "Number: " << number << ", Pi: " << pi << std::endl;

    // Using decltype to determine the type of an expression
    int x = 5;
    double y = 2.5;
    decltype(x + y) result; // The type of 'result' will be deduced as double

    result = x + y;
    std::cout << "Result: " << result << std::endl;

    return 0;
}
