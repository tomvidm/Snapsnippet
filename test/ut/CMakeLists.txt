project(ut)

set(UT_SOURCES
    test_trivial.cpp
    test_combinatorics.cpp
    test_fraction.cpp
    test_modulararithmetic.cpp
    test_numbertheory.cpp
    test_numbertheory2.cpp
    test_number.cpp
    test_Primes.cpp
    test_ModularArithmetic.cpp
    test_EulerTotient.cpp
    test_FindSorted.cpp
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
    ${Boost_INCLUDE_DIRS}
    )
