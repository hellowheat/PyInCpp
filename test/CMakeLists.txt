cmake_minimum_required(VERSION 3.20)
project(PyInCppTest)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../source)

add_executable(test_pyincpp test.cpp)

enable_testing()
add_test(NAME PyInCppTest COMMAND test_pyincpp)
