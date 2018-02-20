cmake_minimum_required(VERSION 3.0)

project(snapsnippet)
set(CMAKE_CXX_STANDARD 11)
set(GTEST_DIR "${CMAKE_SOURCE_DIR}/lib/googletest/googletest")
set(GTEST_INCLUDE_DIR "${GTEST_DIR}/include")

# For windows
# set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)

find_package(Boost)

#add_subdirectory(src)
add_subdirectory(test/ut)
add_subdirectory(lib/googletest/googletest)