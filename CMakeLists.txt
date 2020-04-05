cmake_minimum_required(VERSION 3.0)

project(Computer VERSION 0.1 LANGUAGES C)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_C_STANDARD 99)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/CMakeModules/")

include_directories(include)

add_subdirectory(src)
add_subdirectory(tests)