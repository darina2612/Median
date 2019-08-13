cmake_minimum_required(VERSION 3.0.2)

project(Median)

set(SOURCES Median.hpp
            main.cpp)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(Median ${SOURCES})
target_link_libraries(Median ${GTEST_LIBRARIES} pthread)

set_property(TARGET Median PROPERTY CXX_STANDARD 14)
