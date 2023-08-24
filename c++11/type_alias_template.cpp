/*
In traditional C++, typedef can define a new name for the type, but there is no way to define a new
name for the template. Because the template is not a type. E.g:
*/

#include <vector>
#include <string>

template<typename T, typename U>
class MagicType {
    public:
        T dark;
        U magic;
};


template<typename T>
    using TrueDarkMagic = MagicType<std::vector<T>, std::string>;

int main() {
    TrueDarkMagic<bool> you;
}
