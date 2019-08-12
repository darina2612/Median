cmake_minimum_required(VERSION 3.0.2)

project(Median)

set(SOURCES Median.hpp
            main.cpp)

add_executable(Median ${SOURCES})

set_property(TARGET Median PROPERTY CXX_STANDARD 14)

#Tests
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Link runTests with what we want to test and the GTest and pthread library
add_executable(RunTests tests.cpp)
target_link_libraries(RunTests ${GTEST_LIBRARIES} pthread)
