enable_testing()

find_package(Check REQUIRED)
include_directories(${CHECK_INCLUDE_DIRS})
set(LIBS ${LIBS} ${CHECK_LIBRARIES} hacklib)

file(GLOB tests "check_*.c")

foreach(SINGLE_TEST ${tests})
    get_filename_component(TEST_NAME ${SINGLE_TEST} NAME_WE)
    
    add_executable(${TEST_NAME} ${SINGLE_TEST})
    
    target_link_libraries(${TEST_NAME} ${LIBS})
    
    add_test(${TEST_NAME} ${CMAKE_CURRENT_BINARY_DIR}/${TEST_NAME})
endforeach(SINGLE_TEST)
