cmake_minimum_required(VERSION 3.15)
project(count_number_of_all_words)

set(CMAKE_CXX_STANDARD 17)


if (CMAKE_COMPILER_IS_GNUCC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
endif ()


set(CMAKE_BUILD_TYPE Debug)
find_package(Threads REQUIRED)

set(Boost_USE_STATIC_LIBS OFF) # enable dynamic linking
set(Boost_USE_MULTITHREAD ON)  # enable maltreating
find_package(Boost COMPONENTS filesystem program_options system locale REQUIRED)
INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIR})

file(GLOB_RECURSE SRC "src/*.h")
add_executable(test main.cpp ${SRC})
TARGET_LINK_LIBRARIES(test LINK_PUBLIC ${CMAKE_THREAD_LIBS_INIT})
TARGET_LINK_LIBRARIES(test LINK_PUBLIC ${Boost_LIBRARIES})
