cmake_minimum_required(VERSION 3.16)
project(test_lab2)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

add_library(lib1 ast.hpp dfa.hpp regex_lib.hpp syntax_tree.hpp)

set_target_properties(lib1 PROPERTIES LINKER_LANGUAGE CXX)

link_libraries(lib1)

add_executable(test_lab2 main.cpp)

find_package(Catch2)

add_executable(test tests/catch2.cpp)

target_link_libraries(test PRIVATE Catch2::Catch2WithMain)
