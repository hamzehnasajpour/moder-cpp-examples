// C++ program to demonstrate working of
// Variadic function Template
#include <iostream>
using namespace std;

// Variadic function Template that takes
// variable number of arguments and prints
// all of them.
template<typename T0, typename... T>
void printf2(T0 t0, T... t) {
std::cout << t0 << std::endl;
if constexpr (sizeof...(t) > 0) printf2(t...);
}

int main() {
	printf2( 	"Pass me any "
		"number of arguments",
		"I will print\n");
	return 0;
}
