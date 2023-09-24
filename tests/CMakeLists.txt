cmake_minimum_required(VERSION 3.12)

set(CMAKE_CXX_STANDARD 17)


add_executable(vector_transformation_tests
        main.cpp
        TEST_quaternion.cpp
        TEST_rotate_global.cpp
)

find_package(GTest)
target_include_directories(vector_transformation_tests PUBLIC ${GTEST_INCLUDE_DIRS})
target_link_libraries(vector_transformation_tests PRIVATE ${GTEST_BOTH_LIBRARIES} vector_transformation_lib)
target_compile_options(vector_transformation_tests PRIVATE -Wall -Wextra -Wpedantic -Wconversion)


add_test(NAME test_vector_transformation COMMAND vector_transformation_tests)
