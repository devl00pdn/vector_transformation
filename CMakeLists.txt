cmake_minimum_required(VERSION 3.25)
project(quaternion)

set(CMAKE_CXX_STANDARD 17)

add_executable(quaternion main.cpp quaternion/quaternion.h)
