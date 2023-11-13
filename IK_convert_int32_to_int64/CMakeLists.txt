cmake_minimum_required(VERSION 3.27.0)
add_definitions(-std=c++11)
set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")

set(CMAKE_BUILD_TYPE Debug)

project(IK_convert_int32_to_int64)
add_executable(IK_convert_int32_to_int64 IK_convert_int32_to_int64.cpp)