cmake_minimum_required(VERSION 3.2)

project(countsort)

find_package(OpenMP REQUIRED)

if (OPENMP_FOUND)
    set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
endif()

add_executable(serial   src/countsort-serial.c)
add_executable(parallel src/countsort-parallel.c)
