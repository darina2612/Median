cmake_minimum_required(VERSION 3.0.2)

project(Median)

set(SOURCES main.cpp)

add_executable(Median ${SOURCES})

set_property(TARGET Median PROPERTY CXX_STANDARD 14) 
