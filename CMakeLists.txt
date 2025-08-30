cmake_minimum_required(VERSION 3.20)
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
        Gui.cpp
        Gui.h
)

target_link_libraries(TimerQt Qt5::Widgets)
include(CTest)
enable_testing()
add_subdirectory(test)

qt5_add_resources(APP_QRC
        resources.qrc
)
target_sources(TimerQt PRIVATE ${APP_QRC})

