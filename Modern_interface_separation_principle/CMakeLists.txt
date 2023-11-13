cmake_minimum_required(VERSION 3.27.7)
add_definitions(-std=c++20)
set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")

set(CMAKE_BUILD_TYPE Debug)

find_package(Boost)
include_directories(${Boost_INCLUDE_DIRS})
link_directories(${Boost_LIBRARY_DIRS})

project(modern_interface_separation_principle)
add_executable(modern_interface_separation_principle modern_interface_separation_principle.cpp)