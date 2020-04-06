cmake_minimum_required(VERSION 3.0)

project(Computer VERSION 0.1 LANGUAGES C)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_C_STANDARD 99)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/CMakeModules/")

include_directories(include)

file(GLOB hacksrc src/*/*.c)
add_library(hacklib ${hacksrc})
add_executable(comp src/main.c ${hacksrc})

enable_testing()
add_library(unity STATIC deps/unity/src/unity.c)
target_include_directories(unity PUBLIC deps/unity/src)

file(GLOB testfiles tests/*.c)
foreach(SINGLE_TEST ${testfiles})
    get_filename_component(TEST_NAME ${SINGLE_TEST} NAME_WE)

    add_executable(${TEST_NAME} ${SINGLE_TEST})
    target_link_libraries(${TEST_NAME} hacklib unity)
    
    add_test(test_${TEST_NAME} ${TEST_NAME})
endforeach(SINGLE_TEST)