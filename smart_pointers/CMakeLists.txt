cmake_minimum_required(VERSION 3.23)
project(std_basics)

set(CMAKE_CXX_STANDARD 14)

add_executable(sp smart_pointers.cpp ../smart_pointers/smart_pointers.cpp)
