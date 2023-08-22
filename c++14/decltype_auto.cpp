#include <iostream>

std::string lookup1(){
    return std::string("lookup1");
}

int lookup2(){
    return 255;
}

decltype(auto) look_up_a_string_1() {
    return lookup1();
}

decltype(auto) look_up_a_string_2() {
    return lookup2();
}


int main() {
    std::cout << look_up_a_string_1() << std::endl;
    std::cout << look_up_a_string_2() << std::endl;

    return 0;
}
