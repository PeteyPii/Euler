cmake_minimum_required(VERSION 3.12)
project(Euler)

include_directories(src)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall")

file(GLOB_RECURSE SOURCE_FILES src/*.cpp)
add_executable(euler ${SOURCE_FILES})
