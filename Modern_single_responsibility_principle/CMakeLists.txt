cmake_minimum_required(VERSION 3.27.0)
add_definitions(-std=c++20)
set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")

set(CMAKE_BUILD_TYPE Debug)

project(modern_single_responsibility_principle)
add_executable(modern_single_responsibility_principle modern_single_responsibility_principle.cpp)