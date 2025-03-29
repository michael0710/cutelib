# CMakeLists.txt for CUteLib (OS independent C utility library)
cmake_minimum_required(VERSION 3.13.0)

project(CUteLib VERSION 0.1.0 LANGUAGES C)

set(BUILD_TESTING ON)
include(CTest)

add_subdirectory(linkedlist)
add_subdirectory(ringbuf)
