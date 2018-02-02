project(ut)

set(UT_SOURCES
    test_trivial.cpp
    test_combinatorics.cpp
    test_modulararithmetic.cpp
    test_numbertheory.cpp
    )

add_executable(unittests
    ${gtest_SOURCE_DIR}/src/gtest_main.cc
    ${UT_SOURCES}
    )

set_target_properties(unittests
    PROPERTIES 
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin-ut
    )

target_link_libraries(unittests
    gtest
    )

target_include_directories(unittests PUBLIC 
    ${GTEST_INCLUDE_DIR}
    ${GTEST_DIR}
    ${SRC_DIR}
    )
