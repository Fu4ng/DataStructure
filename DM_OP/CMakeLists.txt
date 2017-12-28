cmake_minimum_required(VERSION 3.8)
project(DM_OP)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp DM_OP.cpp DM_OP_h.h)
add_executable(DM_OP ${SOURCE_FILES})