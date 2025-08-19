cmake_minimum_required(VERSION 4.0)
project(Timer)

set(CMAKE_CXX_STANDARD 20)
find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_executable(TimerQt
        main.cpp
        Data.cpp
        Data.h
        Tempo.cpp
        Tempo.h
        Timer.cpp
        Timer.h
)

target_link_libraries(TimerQt Qt5::Widgets)