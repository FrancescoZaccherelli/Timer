cmake_minimum_required(VERSION 3.20)


add_subdirectory(googletest-main)

file(GLOB TEST_SOURCES CONFIGURE_DEPENDS *.cpp)

add_executable(unit_tests ${TEST_SOURCES}
        Timer_test.cpp
        Data_test.cpp
        Tempo_test.cpp
)

target_sources(unit_tests PRIVATE
        ${CMAKE_SOURCE_DIR}/Data.cpp
        ${CMAKE_SOURCE_DIR}/Tempo.cpp
        ${CMAKE_SOURCE_DIR}/Timer.cpp

)

target_include_directories(unit_tests PRIVATE
        ${CMAKE_SOURCE_DIR}
)


target_link_libraries(unit_tests PRIVATE gtest_main)

include(GoogleTest)
gtest_discover_tests(unit_tests)
