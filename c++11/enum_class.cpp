/*
Issues and limitations in traditional C++ enum:
    * Lack of Scoping
    * Implicit Conversion to int
    * Type Safety
    * Forward Declaration
    * Limited Control
     
    This is an example for enum class a feature in C++11:

*/
#include <iostream>

// Define an enum class named Color with three values
enum class Color {
    Red,
    Green,
    Blue
};

int main() {
    // Declare a variable of type Color and assign a value
    Color myColor = Color::Green;

    // Compare the value of myColor
    if (myColor == Color::Green) {
        std::cout << "The color is Green." << std::endl;
    } else {
        std::cout << "The color is not Green." << std::endl;
    }

    return 0;
}
