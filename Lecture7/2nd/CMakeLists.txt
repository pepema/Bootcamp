cmake_minimum_required(VERSION 3.5.1)
project(car_shop)
add_executable(PROJECT_NAME
               src/main.cpp
               src/car_shop.cpp
               src/linked_list.cpp
               )
include_directories(include)