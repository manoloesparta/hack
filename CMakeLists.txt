cmake_minimum_required(VERSION 3.0)

project(Computer VERSION 0.1 LANGUAGES C)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_C_STANDARD 99)

include_directories(include)

file(GLOB srcfiles src/*/*.c)

add_executable(comp src/main.c ${srcfiles})