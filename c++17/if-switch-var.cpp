/* 
you're using an init-statement in a selection statement (such as an if or switch statement), 
which is a feature introduced in C++17. The init-statement allows you to define and initialize 
variables directly within a selection statement's scope.
*/
#include <iostream>
#include <vector>
#include <algorithm>
int main() {
    std::vector<int> vec = {1, 2, 3, 4};
    // since c++17, can be simplified by using `auto`
    const std::vector<int>::iterator itr = std::find(vec.begin(), vec.end(), 2);
    if (itr != vec.end()) {
        *itr = 3;
    }
    if (const std::vector<int>::iterator itr = std::find(vec.begin(), vec.end(), 3);
        itr != vec.end()) {
        *itr = 4;
    }
    // should output: 1, 4, 3, 4. can be simplified using `auto`
    for (std::vector<int>::iterator element = vec.begin(); element != vec.end(); ++element)
        std::cout << *element << std::endl;
    return 0;
}