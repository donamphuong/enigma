cmake_minimum_required(VERSION 3.6)
project(cenigma_npd215)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    Main.cpp
    )

add_executable(cenigma_npd215 ${SOURCE_FILES})