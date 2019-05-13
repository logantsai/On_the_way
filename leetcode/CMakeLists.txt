cmake_minimum_required (VERSION 2.8)

project (leetcode)

message("-------------------------------------")
message("CMAKE_SOURCE_DIR= ${CMAKE_SOURCE_DIR}")
message("CMAKE_BINARY_DIR= ${CMAKE_BINARY_DIR}")
message("PROJECT_BINARY_DIR= ${PROJECT_BINARY_DIR}")
message("PROJECT_SOURCE_DIR= ${PROJECT_SOURCE_DIR}")
message("CMAKE_CURRENT_SOURCE_DIR= ${CMAKE_CURRENT_SOURCE_DIR}")
message("CMAKE_CURRENT_BINARY_DIR= ${CMAKE_CURRENT_BINARY_DIR}")

message("--------- self define ---------------")
file (GLOB Project_SOURCES
    "${PROJECT_SOURCE_DIR}/common/*.cpp"
)
message("Project_SOURCES= ${Project_SOURCES}")

if(1)
include_directories (common/)
aux_source_directory (${PROJECT_BINARY_DIR}/../ cpp_src)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")

add_executable (a.out ${cpp_src} ${Project_SOURCES})
endif()

