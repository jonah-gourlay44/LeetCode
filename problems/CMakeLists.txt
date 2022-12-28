set(SOLUTIONS
    src/node_ancestor_max_diff.cpp
    src/burst_balloons.cpp
)

add_executable(${PROJECT_NAME}_test
    ${SOLUTIONS}
    src/main.cpp
)

target_link_libraries(${PROJECT_NAME}_test
    ${GTEST_LIBRARIES}
    pthread
)