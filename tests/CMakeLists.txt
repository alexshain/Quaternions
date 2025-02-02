cmake_minimum_required(VERSION 3.10)
project(RescaleTests)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

enable_testing()

find_package(GTest REQUIRED)
include_directories(/opt/homebrew/Cellar/googletest/1.15.2/include)
link_directories(/opt/homebrew/Cellar/googletest/1.15.2/lib)

add_executable(quaternion_test testQuaternionOperations.cpp )

target_link_libraries(quaternion_test gtest gtest_main pthread quaternion_operations)

add_test(NAME QuaternionOperationsTest COMMAND quaternion_test)
