cmake_minimum_required(VERSION 3.15)
project(lab_1_speed_testing)

set(CMAKE_CXX_STANDARD 14)

# PVS Studio
#include(PVS-Studio.cmake)
#SET(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if (CMAKE_COMPILER_IS_GNUCC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
endif ()

#set(CMAKE_VERBOSE_MAKEFILE ON)
#set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_BUILD_TYPE Release)


find_package(Boost COMPONENTS filesystem REQUIRED)
find_package(Qt5Core REQUIRED)
INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIR})
INCLUDE_DIRECTORIES(${Qt5Core_INCLUDE_DIR})

file(GLOB_RECURSE SRC "include/*.h" "src/*.cpp")

add_executable(double_cast_test main.cpp ${SRC})
TARGET_LINK_LIBRARIES(double_cast_test LINK_PUBLIC ${Boost_LIBRARIES})
TARGET_LINK_LIBRARIES(double_cast_test LINK_PUBLIC ${Qt5Core_LIBRARIES})
set_property(TARGET double_cast_test PROPERTY POSITION_INDEPENDENT_CODE ON)


#####################################
## create own target for library
#pvs_studio_add_target(TARGET ${PROJECT_NAME}.analyze ALL
#        ANALYZE double_cast_test
#        OUTPUT FORMAT errorfile
#        MODE GA:1,2,3 OP:1,2,3 GA:1,2,3 OP:1,2,3 64:1,2,3 CS:1,2,3 MISRA:1,2,3
#        LOG target_${PROJECT_NAME}.err)

#####################################
