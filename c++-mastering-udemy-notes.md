## General

### C++:
* C programming language extended
* OOP
* Multipurpose
* Multiplatform
* Run near the hardware
* C/C++ Code -> Compiler -> Assembly (machine codes)

### Modern and Classic C++:
* Classic < C++98
* Modern  > C++11 (11,14,17,20)


### C++ Components:
* Core Feature
* Standard Library (iostream, ...)
* STL (Containers, Alg, ...)


## Variable and Data types
### Variables:
* int
* double
* float
* char
* bool
* void
* auto
* ...

```cpp

int number1 = 15;           // decimal
int number2 = 017           // oct
int number3 = 0x0f          // hex
int number4 = 0b00001111    // bin

```

### Variable initialization:
* Braced initialization
* Functional initialization
* Assignment initialization

```cpp
int number1;        // garbage value
int number2{};      // initialize to zero
int number3{15};    // initialize to 15
int number4{number1+number2};
                    // OK
int number {2.9};   // information lost : error or warning
```

```cpp
int number1(1);
int number2(2.9);   // information lost without error --> NOT USE IT
```

```cpp
int number1=1;
int number2=2.9;    // information lost without error --> NOT USE IT
```

Modifiers:
* int :: signed int
* sizeof(unsigned int) = sizeof(signed int) = 4 bytes
* sizeof(short) = 2 bytes
```cpp
short number1;                  // 2 bytes
short int number2;              //
signed short number3;           //
signed short int number4;       //
unsigned short int number5;     //
```
* sizeof(long) = 4 or 8 bytes
```cpp
long number1;                   // 4 or 8 bytes
long int number2;               //
signed long number3;            //
signed long int number4;        //
unsigned long int number5;      //
```
* sizeof(long long) = 8 bytes
```cpp
long long number6;              // 8 bytes
long long int number7;          // 
signed long long number8;       //
signed long long int number9;   //
unsigned long long int number10;//
```
### Fractional Types
* float         size: 4     precision: 7
* double        size: 8     precision: 15   (default)
* long double   size: 16    precision>double

```cpp
double number1 {192400023};
double number2 {1.92400023e8};
double number3 {1.924e8}
double number4 {0.00000000003498};
double number5 {3.498e-11};
```

**Control the precision in std::cout**
```cpp
#include <iomanip>
std::cout << std::setprecision(20);
```

* add suffix to have more clarity, if it's `float` use like this `0.1234456789f` otherwise it will cast as double in the memory.
also you can you `L` for `long double`

**n(floating point)/0 = infinity (+/-)**
**0.0/0.0 = NaN**

### Boolean
* sizeof(bool) = 1 byte
* init
```cpp
bool red_light {true};
```
* print as true or false
```cpp
std::cout << std::boolalpha
```

### Char and Text

```cpp
char char1 {'a'};
std::cout << char1 << std::endl;
std::cout << static_cast<int>char1 << std::endl;
```


### auto variable
* let the compiler deduce the type
* examples:
```cpp
auto var1{12};
auto var2{12.1};
auto var3{12.1f};
auto var4{12.1l};
auto var5{'a'};
auto var6{123u};
auto var7{123ul};
auto var8{123ll};
```

## Operation on data
### Operations
* READ C++ Operator Precedence : https://en.cppreference.com/w/cpp/language/operator_precedence
* Priotrize with `()`

### Formatting
* `std::cout`
* `std::endl`
* `std::flush`
* `std::setw(10)` : `std::cout << std::setw(10) << "lastname" << std::setw(10) << "firstname" << std::endl` // justification
* `std::right` or `std::left`   // right/left justification
* `std::setfil("")`             // fill char in empty spaces
* `std::boolalpha`
* `std::showpos` or `std::noshowpos`
* `std::dec` or `std::hex` or `std::oct` : `std::cout << std::hex << variable << std::endl;`
* `std::showbase` or `std::noshowbase` // print like 0x..., 0.. or ...
* `std::uppercase` or `std::nouppercase`
* `std::scientific` or `std::fixed`
* `std::setprecision()` // floating point precisions
* `std::showpoint` or `std::noshowpoint` // force to show the fixed points based on the precision

### Numeric Limits
* `#include <limits>`
* `std::numeric_limits<T>::min` , `max`
* `std::numeric_limits<T>::is_signed`
* `std::numeric_limits<T>::digits`

### Math functions
* `include <cmath>`
* `std::exp()`
* `std::floor()`
* `std::ceil()`
* `std::pow( , )`
* `std::log()`
* `std::log10()`
* `sqrt()`
* `std::round()`
* `std::abs()`

**integral types less than 4 bytes in size don't support arithmatic operations, like `char` and `short int`**

## Literals and Constants
* Literals don't use any memory. 
* Constants: you can init and can't be change afterward.
* Constant Expression: Compile time computations --> optimization
  - `static_assert()` : check constexpr at compile time to check the value
```cpp
constexpr int square(int x) {
    return x * x;
}

constexpr int result = square(5);
...
static_assert(SOME_LIB_MAJOR_VERSION == 123)
```

```cpp
constexpr bool condition {false};

if constexpr (condition){ 
    // The main advantage of using constexpr in the condition of if 
    // constexpr is that it allows the compiler to perform conditional
    // compilation by evaluating the condition at compile time.
    std::cout << "Condition is true" << std::endl;
} else {
    std::cout << "Condition is false" << std::endl;
}
```


* constinit: C++20, only for static or thread local storage
```cpp
* It is used to specify that a variable must be initialized during the program's startup phase and is not allowed to have dynamic initialization.
* It is particularly useful in scenarios where you want to ensure that a variable is initialized with a constant expression before any dynamic initialization occurs.
* It provides better performance guarantees compared to const in terms of avoiding dynamic initialization.
```

## Data conversions, overflow and underflow

**All variables in an expression should be of the same type**

### Implicit data conversions
* Conversion done by the compiler without your involvement. 
* Conversions are always done from the smallest to the largest type.

#### Conversion guidline
`int` -> `unsigned int` -> `long`
-> `unsigned long` -> `long long` -> `unsigned long long`
-> `float` -> `double` -> `long double`

#### Implicit conversion in assignments
```cpp
double d{10.2};
int x = d;
```

### Explicit data conversions
* Conversions are actively intiated by the developer.
* `static_cast<>()`
```cpp
double x{10.1};
double y{12.3};

sum = static_cast<int>(x) + static_cast<int>(y);
sum = static_cast<int>(x+y);
```

* Old style C-cast

#### Why C++ cast?
* You can search in the code easily. just search the `static_cast`.
* `static_cast` is checked by the compiler, so if the types are not compatible you will get a compiler error.


### Overflow and Underflow
.


## Bitwise operators
* print value as binary
```cpp
#include <bitset>
std::cout << std::bitset<16>(data) << std::endl;
```

## Variable lifetime and scope
* local (block, automatic)
* static
* dynamic

## Control Flow
### Short circut evaluation
* AND: if one of the operands is `false`, the result is `false`. Put operands likely to be `false` first.
* OR : if one of the operands is `true`, the result is `true`. Put operands likely to be `true` first.
**WHY?** computing some of the operands in the expression can be expensive. if short circuit is possible, such expensive computations can be avoided.


### if with initializer
```cpp
if(int i{10};go)
    ...
```

### switch with initializer
```cpp
switch (double h{10.1}; shape){
    case ....
}
```

### switch scope
**Strongly recommended not declaring the variables inside the switch blocks. Use an initializer of a plain old variable inside the switch block instead**

```cpp
switch(val)  
{  
  int x;              // valid
  int y{0};           // compile error
case 0:  
  {
    int newVal = 42;  // valid
  }
  break;
case 1:  
  int newVal2 = 42;  // compile error
  break;
case 2:
  int newVal3;       // valid
  break;
}
```

### Comma operator
```cpp
int number1{10};
int number2{20};
int number3{25};
int increment{5};

int result = (number1*=++increment, number2 - (++increment), number3+=++increment);

// number1 = 60
// number2 = 20
// number3 = 33
// result  = 33
```

### Range based for loop

```cpp
int vs[] {1,2,3,4,5};
for (int v: vs){
  // ...
}

for (int i{5}; int v:{1,2,3,4,5}){
  // ...
}
```

### infinit loops
```cpp
for(){}

for (int i{}; ; i++){}

while(true){}

while(){}

do{

}while(true);
```


## Arrays
### Size of array
```cpp
int scores [] {1,2,3,4,5};
int count { std::size(scores) };  // C++17
//or
int count  = sizeof(scores) / sizeof(scores[0]); // total size of array / size of one item
```

### Char Array
```cpp
char message [] = {'h', 'i', '\0'}; // it may works without NULL at the end, but sometimes it's also going to print
                                    // some garbage char after
char message [] = { "Hello" };

```

### Random numbers
* `std::rand()` : generate number between 0 and RAND_MAX
* `std::srand( )` // seed to generate random numbers
```cpp
std::srand(std::time(0));
```

## Pointers
### Char pointers
```cpp
const char * message = {"Hello"};     // Best case is using const
std::cout << * message << std::endl;  // just print H
std::cout << message << std::endl;    // print Hello
```

```cpp
const char *messages[] {
  "message1",
  "message2",
  "..",
  ...
};
```

### Const pointer and pointer to const
```cpp
// POINTER TO CONST
int number{123};
const int *p_number{&number}; // can't modify the number through p_number 
                              // regardless of whether the data itself is declared const or not
*p_number=321;                // compiler error
```

```cpp
const int number{123};
int *p_number{&number};       // compiler error -> should be update to point to const
```

```cpp
// CONST POINTER
int number{123};
int * const p_number{&number};
*p_number=123;

int number1{222};
p_number=&number1;            // compiler error
```

### Pointers and Arrays
They are similar.
```cpp
int s[] {1,2};
int *p {s};

std::cout << s << std::endl; // is similare std::cout << p << std::endl;

s[0]=2; // is similar p[0]=2;
```

**`std::size()` doesn't work for raw pointers.**

### Pointers Arithmatics
```cpp
int a[]={1,2,3};
int *p{a};

p++; // pointes to 2
p++; // pointes to 3

int *p1 {a+0};  // start
int *p2 {a+2};  // end

std::cout << p2-p1 << std::endl; // 2
```

### Pointer differences
```cpp
...
std::ptrdiff_t p = p2-p1;       // 2, specific type for pointer diferrences without being worry about the large differences and negative values
```


### Stack and Heap
* Stack:
  - memory is finite.
  - not full control of the memory lifetime
  - lifetime is controlled by the scope mechanism.
  - local var, function calls and ..
* Heap:
  - memory is finite.
  - full control of when memory is allocated and when it's released.
  - lifetime is controlled explicitly through new and delete operation.
  - dynamic memory allocation.

### Memory allocation
```cpp
int *p1{new int};
int *p2{new int {12}};

delete p2;
p2 = nullptr;
delete p1;
p1 = nullptr;
```

### memory allocation failure
```cpp
int *p{new int[1000000000000000000000]};
```
1. `std::nothrow` : to not throw an exception and not termination
```cpp
int *p{new(std::nothrow) int[1000000000000000]};
if (p!=nullptr){
  //pointer is valid
}
```

2. `try/catch`
```cpp
try{
  int *p{new int[1000000000000000]};
} catch (std::exception &ex){
  std::cout << ex.what() << std::endl;
}
```

### Release mamory of arrays
```cpp
int *p{new int [12]};

delete[] p;
p=nullptr;
```

## References

### References vs Pointers
* Reference:
  - don't use dereferencing for reading and writing
  - can't be changed to reference something else
  - must be initialized at declaration
* Pointers:
  - must go through derefrencing operator to read/write
  - can be changed to point somewhere else
  - can be declared unintialized 


### references and const
```cpp
int age{22};
const int &ref_age{age};
```

### Range based references
```cpp
for(auto &s: scores){
  s++;    // modify the original data
}
```

## Characters Manipulations and string
### Manipulations
```cpp
#include <cctype>
std::isalnum(' ');    // is alphanumeric
std::isalpha(' ');    // is alphabetic
std::isblank(' ');    // is blank
std::islower(' ');    // is lowercase
std::isupper(' ');    // is uppercase
std::isdigit(' ');    // is digit
std::toupper(' ');    // to uppercase
std::tolower(' ');    // to lowercase
...

```

### C-String library
```cpp
#include <cstring>
const char message[] {"hello"};
std::strlen(message);   // size of the message and ignores the null char
sizeof(message);        // includes the null char

const char *message {"hello"};
std::strlen(message);
sizeof(message);        // size of the pointer

std::strcmp( , );
std::strcmp( , , n);          // compare n characters
std::strchr(intput,' ');      // find the first occurrence 
std::strrchr(input,' ');      // find last occurence
```


```cpp
std::strcat(dest, src);
std::strncat(dest, src, n);

std::strcpy()
std::strncpy()
```

### std::string
```cpp
#include <string>

std::string str1 = "Hello";
std::string str2 = "world";

std::string str = str1 + str2;
std::string str{str1 + str2};
std::string str = str1.append(str2);
std::string str = str1.append(5, '?');    // appends 5 ? characters
std::string str = str1.append(str16,4,5); // appends a sub-section of another string
                                          //  starting from index 4, 5 characters


// Access to characters in string
std::string str {hello};
str[0]    = 'H';  // h -> H
str.at(1) = 'E';  // e -> E
std::cout << str.front() << " " << str.back << std::endl; //  H o

char &f = str.front();
char &b = str.back();
f = 'H';          // h -> H

//
const char *c_str=str.c_str(); // read only
char *c_str=str.data();        // C++17 - R/W

//
std::string str{};
str.empty()     // true/false
str.size()      // size of the string
str.lenght()    // same as size
str.max_size()  // maximum size of string in your system
str.capacity()  // max string you can store
str.reserver()  // update the capacity
str.shrink_to_fit() // update your string and make it smaller (update the capacity)
str.clear()     // clear it
str.insert(1,1,'3');  // insert one character (3) in index 1
str.erase(start, len);
str.push_back(' ');   // append at the end
str.pop_back();       // remove from end
```

#### `std::string::compare`
```cpp
std::string str;
str.compare("test");
str.compate(1,3,"test");
```

### std::string: replacing, copying, resizing, swapping and search
```cpp
std::string str1{"Hello World!"};
str1.replace(1,2,str_new);

str1.replace(1,2,str_new,21,12);
```

```cpp
std::string str1{"Hello"};
char txt4[15]{};
str1.copy(txt4,11,9);   //copy to txt4
```

```cpp
std::string str1{"Hello"};
str1.resize(10);      // null by default
str1.resize(10,'.');
```

```cpp
std::string str1{"Hello"};
std::string str2{"World"};
str1.swap(str2);
```

```cpp
std::string str1{"123456790_1234567890"};
size_t pos = str1.find("1"); // first 1 index
size_t pos = str1.find("a"); // junk value - a large number = std::string::npos
if(pos == std::string::npos){
  // not found
} else {
  // found
}

size_t pos = str1.find(search_for, index);
```

#### Transforming from/to numbers
```cpp
std::to_string(int/double/float);
```

```cpp
int i = std::stoi(  );
float f = std::stpf(  );
double d = std::stod(  );
...
```

#### Raw string literals
Instead of using 
```cpp
std::string text {"Hello\nWorld"};
```
you can use raw string literals:
```cpp
std::string text {R"(Hello
World)"};
```

`"(` and `)"` are delimiters which c++ is using them for raw literals so maybe you have to use this format sometimes :)
```cpp
std::string text {R"---(Hello "(World)" )---"};
```

#### std::string_view
* size of string_view is fixed and the data stored somewhere else -> impvroved for copy and not memory wasting
* if you change the reference the string_view also will be changed since it's pointing to that reference.

```cpp
  std::string hello{"Hello"};
  std::string_view stv {hello};
  std::cout << stv << std::endl;    // Print: Hello
  hello = "Babye";
  std::cout << stv << std::endl;    // Print: Babye
```

```cpp
#include <string_view>

std::string_view stv{"Hello World"};
stv.remove_suffix(2);
stv.remove_prefix(2);

```
**Dont use non null strings for string_view**


## Functions
### Sized array passed by reference
```cpp
double sum (const double (&scores)[10]){
  // pass array of double with length of 10 by reference. Size is fixed.
}
```

### Default argument
```cpp
void compute(int age = 34){   // set the default values in the declaration

}

compute();
```

### Implicit conversions
```cpp
void print_sum(int a, int b){

}

double a{1.2};
double b{2.1};
print_sum(a,b);   // implicit conversions by compiler ==> data lost
```

```cpp
void print_value(int value){
    std::cout << "Value = " << value << std::endl;
}
 
double value{11.2};
print_value(value);
```

* Implicit conversions doesn't work on pointers.
* If you have to pass a string to a function use string_view as type.

### `constexpr` and `consteval`
```cpp
constexpr int compute1 (int a);
consteval int compute2 (int a);

int a{10};
const int c{10};

int result = compute1(1);             // OK
int result = compute1(a);             // OK
constexpr int result = compute1(a);   // OK
int result = compute1(c);

int result = compute2(1);             // OK
int result = compute2(a);             // compile error
int result = compute1(c);             // OK
```

## Enums and Type aliases

```cpp
enum class Month { Jan, Feb, Mar,     // 0, 1, 2
                   Apr,...};          // 3, ....

enum class Month { Jan = 1, Feb, Mar, // 1, 2, 3
                   ...};              ,, 4, 5

enum class Month { Jan = 1, January=1, Feb=2, February=2, ...};
enum class Month { Jan=1, January=Jan,
                   Feb,   Feburary=Feb,...};

enum class Month { Jan = -30, ....};
enum class Month : unsigned char {Jan, ...};

Month month {Month::Jan};
std::cout << static<int>(month) << std::endl;
sizeof(month); // sizeof(int)

switch(month){
  using enum Month;   // C++20 and GCC>=11
  case Jan:
  ...
  case Feb:
  ...
}
```

### Old enums
```cpp
enum Direction{
  left, right, up, down
};
```

### Type aliases
```cpp
using HugeInt = unsigned long long int;
HugeInt huge_num = {18'446'744'679'709'551ull};
```

```cpp
typedef unsigned long long int HugeInt;
HugeInt huge_num = {....};
```

## Arguments to `main`
```cpp
int main(int argc, char** argv)
int main(int argc, char* argv[])
```

## `std::err`
use `std::err` to send error log messages.

## Getting things out of the function
1. Function should have access to output variable to store -> by reference is prefered (pointer is another option)
2. Function should not have access to modify the input -> make them readonly with `const` keyword.

**In modern compilers returning by value is commonly optimized by the compiler when possible and the function is modified
behind your back to return by reference, avoiding unneccessary copies**

### return by reference
```cpp
int &sum(int &a, int &b){
  int result = a+b;
  return result;        // reference to local var --> undefined behaviour
}

int &sum(int a, int b){
  a+=b;
  return a;             // reference to local var --> undefined behaviour
}
```

### `auto` deduction
```cpp
int x{10};
auto var1{x};   // int (copy)
auto &var2{x};  // int (reference)
```

**For return type deduction you have to put the function declaration before calling it, otherwise the compiler can't detect the return type since it can't see the implementation**

### `std::optional` (C++17)

```cpp
std::optional<int> item{3};
std::cout << item.value() << std::endl;

std::optional<int> age{std::nullopt};       // you must check if has value otherwise => crash
if(age.has_value())
  std::cout << age << std::endl;

std::optional<std::string> name{};          // std::nullopt
name = "Felafel";
std::string name1 = name.value_or("pizza"); // if value -> return it otherwise `pizza` as default value
```

## Function overloading
just for paremeters, return value is not part of signature.
* order of parameters
* number of parameters
* types of parameters

```cpp
void say_my_name(const std::string &name);
void say_my_name(std::string name);

std::string name{"Hamzeh"};
say_my_name(name);            // compiler error - ambgious call
```

```cpp
double max(double a, double b);
int &max(const int &a, const int &b);

char a{2};
char b{3};
auto result = max(a,b);   // double max will be called !!!
                          // Since the implicit conversions dont work with a function that takes param by non-const ref
```

### redefinition implementation
```cpp
int max(int a, int b){
  return (a>b)? a: b;
}

int max(const int a, const int b){
  return (a>b)? a: b;
}

// compiler error -> the implementation is equal => compiler thinks they are the same => redefinition function
```

```cpp
int max(const int*a, const int* b){
  return (*a>*b)? *a: *b;
}

int max(const int* const a, const int* const b){
  return (*a>*b)? *a: *b;
}

// compiler error -> the implementation is equal => compiler thinks they are the same => redefinition function
```

### overloading with default value
```cpp
void print_age(int age=33);
void print_age(long int = 44);

print_age(); // compiler error => confusion since both are valid to call.
```

## Lambda functions 
* Could be without name, anonymous function
* lambda signature
```cpp
[](double a){
  std::cout << "Hello " << a << std::endl;
}(12.1); // defince and call since ()
```

```cpp
auto result = [] (double a, double b) -> double {
  return a + b;
};
```

```cpp
double a{11};
auto func = [a](){
  // capture by value
  std::cout <<a << std::endl;
};

auto func1 = [&a](){
  // capture by ref
  std::cout <<a++ << std::endl;
};

auto func2 = [=](){
  // capture all by value
};

auto func3 = [&](){
  // capture all by ref
};

```

## Functions: misfits
### static variables
* Global variable - outside the main and outside other functions. lifetime = application lifetime
* static variable
```cpp
void func(){
  static int a{0};  // initialize only one time. lifetime = application lifetime
  ..
}
```

### inline functions
Put the presentation of the functions in the code by compiler to reduce function call overhead.
* increasing the code size.
* use it for shodrt and frequently used functions.

### recursive functions
.... :)


## C++ Classes
...

* default ctor
```cpp
Animal() = default;   // empty ctor as default
```

* in `struct` all is `public`, in `class` we can declare as `private` or `public`

## Function Template

```cpp
template <typename T> T maximum (T a, T b){
  return (a>b)? a : b;
}
maximum<double>(a,b);     // explicitly say that we want the double version called
```

```cpp
template <typename T> T& maximum(T &a, T &b);   // template by references
```