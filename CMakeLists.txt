cmake_minimum_required(VERSION 3.3)
project(ex2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES MIR.cpp Song.cpp Song.h InstrumentalSong.cpp InstrumentalSong.h LyricalSong.cpp LyricalSong.h
        Manager.cpp Manager.h parameters.cpp parameters.h Mood.cpp Mood.h)
add_executable(ex2 ${SOURCE_FILES})