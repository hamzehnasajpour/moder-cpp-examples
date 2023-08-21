cmake_minimum_required (VERSION 3.10)
project(audio)

set(CMAKE_CXX_STANDARD 17)

add_executable(explicit explicit.cpp)
add_executable(nullptr nullptr.cpp)
add_executable(constexpr constexpr.cpp)
add_executable(if-switch-var if-switch-var.cpp)
add_executable(initializer_list initializer_list.cpp)
add_executable(structured_binding structured_binding.cpp)
add_executable(tuple tuple.cpp)
add_executable(auto_decltype auto_decltype.cpp)