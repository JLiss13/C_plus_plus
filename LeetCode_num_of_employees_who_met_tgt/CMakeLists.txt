cmake_minimum_required(VERSION 3.27.0)
add_definitions(-std=c++11)
set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")

set(CMAKE_BUILD_TYPE Debug)

project(leetcode_num_of_employees_who_met_tgt)
add_executable(leetcode_num_of_employees_who_met_tgt leetcode_num_of_employees_who_met_tgt.cpp)