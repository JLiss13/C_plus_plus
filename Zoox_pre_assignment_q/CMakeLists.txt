cmake_minimum_required(VERSION 3.27.0)
add_definitions(-std=c++11)
set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")

set(CMAKE_BUILD_TYPE Debug)

project(zoox_pre_assignment_q)
add_executable(zoox_pre_assignment_q zoox_pre_assignment_q.cpp)