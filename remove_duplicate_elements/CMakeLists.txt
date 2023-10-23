cmake_minimum_required(VERSION 3.0.0)
project(remove_duplicate_elements VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_executable(remove_duplicate_elements remove_duplicate_elements.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

# Include the current source directory as an include directory
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
