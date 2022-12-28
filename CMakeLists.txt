cmake_minimum_required(VERSION 2.8.3)
project(LeetCode)

find_package(GTest REQUIRED)

include_directories(
    ${GTEST_INCLUDE_DIRS}
    utils/include
)

add_subdirectory(
    problems
)