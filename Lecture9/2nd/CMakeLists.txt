cmake_minimum_required(VERSION 3.15)
project(2nd)
add_executable(2nd 
               shapes/src/shape.cpp 
               shapes/te>st/test_main.cpp)
include_directories(shapes/include shapes/test/include)