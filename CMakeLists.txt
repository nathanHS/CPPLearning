cmake_minimum_required(VERSION 3.7)
project(CPPLearning)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp head.h source.cpp)
add_executable(CPPLearning ${SOURCE_FILES})