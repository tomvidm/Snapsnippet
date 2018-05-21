project(projecteuler-12)

add_executable(p12
    main.cpp
)

target_include_directories(p12 PUBLIC 
    ${SRC_DIR}
)