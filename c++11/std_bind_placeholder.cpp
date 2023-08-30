#include <iostream>
#include <functional>

// A simple function that takes three arguments
int sum(int a, int b, int c) {
    std::cout << "a=" << a << ", b=" << b << " ,c=" << c << std::endl;
    return a + b + c;
}

int main() {
    // Create a callable object by binding the first two arguments of the 'sum' function
    auto addFiveAndSix = std::bind(sum, 5, 6, std::placeholders::_1);

    int result = addFiveAndSix(10);

    std::cout << "Result: " << result << std::endl; // Output: 21

    return 0;
}
