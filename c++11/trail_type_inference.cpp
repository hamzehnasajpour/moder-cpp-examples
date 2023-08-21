#include <iostream>

// See trail_type_inference example in c++17
auto add(int a, int b) -> decltype(a + b) {
    return a + b;
}

int main() {
    int x = 5, y = 3;

    auto result = add(x, y);
    std::cout << "Result: " << result << std::endl;

    return 0;
}
