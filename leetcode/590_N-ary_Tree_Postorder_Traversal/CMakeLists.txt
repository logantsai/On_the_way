cmake_minimum_required (VERSION 2.8)

project (leetcode_590)

include_directories (../common)
aux_source_directory (. cpp_src)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")

add_executable (a.out ${cpp_src} ../common/TreeTools.cpp)

