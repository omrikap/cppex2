cmake_minimum_required(VERSION 3.3)
project(ex2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES MIR.cpp Song.cpp Song.h InstrumantalSong.cpp InstrumantalSong.h LyricalSong.cpp LyricalSong.h
        Manager.cpp Manager.h)
add_executable(ex2 ${SOURCE_FILES})