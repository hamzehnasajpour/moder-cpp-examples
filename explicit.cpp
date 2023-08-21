#include <iostream>

class Distance {
private:
    double meters;

public:
    explicit Distance(double meters = 0.0) : meters(meters) {}

    void print() const {
        std::cout << meters << " meters" << std::endl;
    }
};

int main() {
    // By making the constructor explicit, you ensure that the conversion from double to Distance is explicit and clear, 
    // reducing the chance of introducing bugs due to unintended conversions.

    // Distance d1 = 10.5;  // Error: No implicit conversion
    Distance d1(10.5);

    d1.print();

    Distance d2(15.0);
    d2.print();          // Output: 15 meters

    return 0;
}
