cmake_minimum_required(VERSION 2.6)

PROJECT(testcpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++11")

add_executable( variadic_example
    variadic_example.cpp
)

add_executable( auto_example
    auto_example.cpp
)
