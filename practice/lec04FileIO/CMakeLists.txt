cmake_minimum_required(VERSION 3.14)
project(lec04FileIO)

configure_file(data2.txt data2.txt COPYONLY)

set(CMAKE_CXX_STANDARD 14)

add_executable(lec04FileIO main.cpp)