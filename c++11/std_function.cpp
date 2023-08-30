#include <iostream>
#include <functional>

// Example functions with different signatures
int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

int main() {
    // Declare a std::function with the signature of int(int, int)
    std::function<int(int, int)> operation;

    // Assign different functions to the std::function
    operation = add;  // Assign the add function
    std::cout << "Result of add: " << operation(5, 3) << std::endl;

    operation = subtract;  // Assign the subtract function
    std::cout << "Result of subtract: " << operation(10, 4) << std::endl;

    operation = multiply;  // Assign the multiply function
    std::cout << "Result of multiply: " << operation(6, 7) << std::endl;

    return 0;
}
