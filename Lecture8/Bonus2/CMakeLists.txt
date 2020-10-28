cmake_minimum_required(VERSION 3.15)
project(bonus2)

include(FindPCAP.cmake)
link_libraries(${PCAP_LIBRARY})

add_executable(bonus2 src/main.cpp)
target_link_libraries(bonus2 pcapOpenner)
target_include_directories(bonus2 PUBLIC include)
target_link_directories(bonus2 PUBLIC . lib)