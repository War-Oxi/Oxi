cmake_minimum_required(VERSION 3.21)
project(file_partition)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(file_partition
        Car.cpp
        Car.h
        RacingMain.cpp)
