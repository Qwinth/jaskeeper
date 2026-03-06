cmake_minimum_required(VERSION 3.10)

project(jaskeeper)
project(jasc)

add_executable(jaskeeper src/jaskeeper/vm/main.cpp src/jaskeeper/vm/core/primitives.cpp)
add_executable(jasc src/jaskeeper/compiller/main.cpp)

include_directories(jaskeeper PRIVATE include/)
include_directories(jasc PRIVATE include/)