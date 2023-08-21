/*
Structured bindings provide functionality similar to the multiple return values provided in other
languages. In the chapter on containers, we will learn that C++11 has added a std::tuple container
for constructing a tuple that encloses multiple return values. But the flaw is that C++11/14 does not
provide a simple way to get and define the elements in the tuple from the tuple, although we can unpack
the tuple using std::tie But we still have to be very clear about how many objects this tuple contains,
what type of each object is, very troublesome.
*/

#include <iostream>
#include <tuple>

std::tuple<int, double, std::string> f() {
    return std::make_tuple(1, 2.3, "456");
}

int main() {
    auto [x, y, z] = f();
    std::cout << x << ", " << y << ", " << z << std::endl;
    return 0;
}