cmake_minimum_required(VERSION 2.8.3)

find_package(GTest REQUIRED)

include_directories(
    include
    ${GTEST_INCLUDE_DIRS}
)

add_executable(test_hash_set src/test_hash_set.cpp)
add_executable(test_hash_map src/test_hash_map.cpp)
add_executable(contains_duplicate src/contains_duplicate.cpp)
add_executable(single_number src/single_number.cpp)

target_link_libraries(test_hash_set
    ${GTEST_LIBRARIES}
    pthread
)

target_link_libraries(test_hash_map
    ${GTEST_LIBRARIES}
    pthread
)

target_link_libraries(contains_duplicate
    ${GTEST_LIBRARIES}
    pthread
)

target_link_libraries(single_number
    ${GTEST_LIBRARIES}
    pthread
)