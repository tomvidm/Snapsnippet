cmake_minimum_required(VERSION 3.0)

project(snapsnippet)

set(GTEST_DIR "${CMAKE_SOURCE_DIR}/lib/googletest/googletest")
set(GTEST_INCLUDE_DIR "${GTEST_DIR}/include")

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)

#add_subdirectory(src)
add_subdirectory(test/ut)
add_subdirectory(lib/googletest/googletest)