cmake_minimum_required(VERSION 4.0)
project(Timer)

set(CMAKE_CXX_STANDARD 20)

add_executable(Timer main.cpp
        Data.cpp
        Data.h
        Tempo.cpp
        Tempo.h
        Timer.cpp
        Timer.h)
