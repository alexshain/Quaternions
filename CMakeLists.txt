cmake_minimum_required(VERSION 3.10)
project(patterns LANGUAGES CXX)

# Стандарт C++
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Указываем путь к исходникам и заголовкам
add_subdirectory(src)
add_subdirectory(tests)
