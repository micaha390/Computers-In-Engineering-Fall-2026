cmake_minimum_required(VERSION 3.25)
project(hw1-peloton-graph)

set(CMAKE_CXX_STANDARD 17)

configure_file(ride_data.txt ride_data.txt COPYONLY)
configure_file(ride_data2.txt ride_data2.txt COPYONLY)
configure_file(ride_data3.txt ride_data3.txt COPYONLY)
configure_file(ride_data4.txt ride_data4.txt COPYONLY)
configure_file(ride_data5.txt ride_data5.txt COPYONLY)

add_executable(hw1-peloton-graph main.cpp)
