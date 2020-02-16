cmake_minimum_required(VERSION 3.15)
project(lab_1_speed_testing)

set(CMAKE_CXX_STANDARD 14)


#set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_BUILD_TYPE Release)

file(GLOB_RECURSE SRC "include/*.h" "src/*.cpp")

add_executable(lab_1_speed_testing main.cpp ${SRC})
