cmake_minimum_required (VERSION 3.10)
project(audio)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)

add_executable(explicit explicit.cpp)
add_executable(nullptr nullptr.cpp)
add_executable(constexpr constexpr.cpp)