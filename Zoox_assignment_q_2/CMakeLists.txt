cmake_minimum_required(VERSION 3.27.0)
add_definitions(-std=c++11)
set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")

set(CMAKE_BUILD_TYPE Debug)

project(zoox_assignment_q_2)
add_executable(zoox_assignment_q_2 zoox_assignment_q_2.cpp)