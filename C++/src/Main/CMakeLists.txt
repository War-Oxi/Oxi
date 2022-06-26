cmake_minimum_required(VERSION 3.21)
project(Main)

set(CMAKE_CXX_STANDARD 14)

add_executable(Main
        Main.cpp MainSource.cpp Main_Header.h MainSourece2.cpp Main_Header2.h)
