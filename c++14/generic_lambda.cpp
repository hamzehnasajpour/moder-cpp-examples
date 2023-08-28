#include <iostream>

void lambda_generic() {
    auto generic = [](auto x, auto y) {
        std::cout << "Type of x Variable: "<< typeid(x).name() << std::endl;
        return x+y;
    };
    std::cout << generic(1, 2) << std::endl;
    std::cout << generic(1.1, 2.2) << std::endl;
}


int main(){
    lambda_generic();
    return 0;
}