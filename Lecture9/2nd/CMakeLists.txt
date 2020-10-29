cmake_minimum_required(VERSION 3.15)
set(CMAKE_BUILD_TYPE Debug)
project(2nd)
add_executable(2nd 
               shapes/src/shape.cpp 
               shapes/test/test_main.cpp)
include_directories(shapes/include shapes/test/include)