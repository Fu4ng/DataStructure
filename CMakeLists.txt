cmake_minimum_required(VERSION 3.8)
project(DataStructure)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES SqList.cpp 3week.cpp LinkList.cpp Josephus.cpp DM_BB/DM_BB.cpp)
add_executable(DataStructure ${SOURCE_FILES})