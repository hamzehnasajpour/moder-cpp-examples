/*
Compare this feature with ./C++17/variable_param_template_exp.cpp
*/

// C++ program to demonstrate working of
// Variadic function Template
#include <iostream>
using namespace std;

// To handle base case of below recursive
// Variadic function Template
void printf2(){
	cout << "I am empty function and "
			"I am called at last.\n";
}

// Variadic function Template that takes
// variable number of arguments and prints
// all of them.
template<typename T0, typename... T>
void printf2(T0 t0, T... t) {
	std::cout << sizeof...(t) << ": " << t0 << endl;
	printf2(t...);
}

template<typename T, typename... Ts>
	void printf3(T value, Ts... args) {
		std::cout << value << std::endl;
		(void) std::initializer_list<T>{([&args] {
			std::cout << args << std::endl;
			}(), value)...};
}

int main() {
	printf2(1, 2, 3.14,
		"Pass me any "
		"number of arguments",
		"I will print\n");
	printf3(1, 2, 3.14,
		"Pass me any "
		"number of arguments",
		"I will print\n");		
	return 0;
}
