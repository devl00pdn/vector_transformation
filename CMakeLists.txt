cmake_minimum_required(VERSION 3.25)
project(quaternion)

set(CMAKE_CXX_STANDARD 17)

add_executable(quaternion_tests include/quaternion.h
        include/rotor.h
        tests/main.cpp
        tests/TEST_quternion.cpp
        tests/TEST_rotate_global.cpp
)

find_package(GTest REQUIRED)
target_include_directories(quaternion_tests PUBLIC include ${GTEST_INCLUDE_DIRS})
target_link_libraries(quaternion_tests PRIVATE ${GTEST_BOTH_LIBRARIES})
target_compile_options(quaternion_tests PRIVATE -Wall -Wextra -Wpedantic -Wconversion)


