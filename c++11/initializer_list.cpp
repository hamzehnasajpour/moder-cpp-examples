/*
Using std::initializer_list:

1. Simplicity and Convenience:
    std::initializer_list allows you to pass a list of values directly as function 
    arguments without the need to explicitly create a container like a vector.
2. Readability:
    When you use std::initializer_list, your function or constructor call clearly
    shows that you're passing a list of values for initialization, 
    which can improve the readability of your code.
3. Avoiding Unnecessary Dynamic Memory Allocation:
    std::initializer_list is designed for lightweight initialization scenarios. 
    It's typically used for smaller sets of values that don't require dynamic memory allocation, 
    making it more memory-efficient compared to a vector.
4. Compile-Time Initialization:
    std::initializer_list is created at compile time, 
    so the initialization process can be optimized by the compiler, 
    potentially leading to improved performance.
5. Suitable for Immediate Use:
    If you only need to process the passed values immediately 
    (e.g., print, calculate, initialize), 
    std::initializer_list can be more efficient since it 
    avoids the overhead of creating and managing a vector.
6. Emphasis on Initialization:
    std::initializer_list conveys the idea of initialization rather than 
    creating a container for later use. If the values are meant to be used 
    for initialization and not stored, using a vector might overemphasize the storage aspect.
    On the other hand, using a vector<int> has its benefits too:
*/
#include <initializer_list>
#include <vector>
#include <iostream>

class MagicFoo {
    public:
        std::vector<int> vec;
        MagicFoo(std::initializer_list<int> list) {
            for (std::initializer_list<int>::iterator it = list.begin(); it != list.end(); ++it)
                vec.push_back(*it);
        }
};

int main() {
    // after C++11
    MagicFoo magicFoo = {1, 2, 3, 4, 5};
    std::cout << "magicFoo: ";
    for (std::vector<int>::iterator it = magicFoo.vec.begin(); it != magicFoo.vec.end(); ++it)
        std::cout << *it << std::endl;
    return 0;
}