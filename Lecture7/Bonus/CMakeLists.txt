cmake_minimum_required(VERSION 3.15)
project(bonus)

include(FindPCAP.cmake)

link_libraries(${PCAP_LIBRARY})

add_executable(${PROJECT_NAME} src/main.cpp)