cmake_minimum_required(VERSION 3.22)
project (test)

add_executable(test recognizer_sm.h recognizer.cpp main.cpp recognizer.hpp recognizer_sm.cpp)
