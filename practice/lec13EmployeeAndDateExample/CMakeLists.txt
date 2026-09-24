cmake_minimum_required(VERSION 3.14)
project(lec13EmployeeAndDateExample)

set(CMAKE_CXX_STANDARD 14)

add_executable(lec13EmployeeAndDateExample main.cpp Employee.cpp Employee.h Date.cpp Date.h)