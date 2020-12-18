cmake_minimum_required(VERSION 2.8.3)

find_package(GTest REQUIRED)

include_directories(
    include
    ${GTEST_INCLUDE_DIRS}
)

add_executable(merge_sorted_arrays src/merge_sorted_arrays.cpp)
add_executable(check_if_N_double src/check_if_N_double.cpp)
add_executable(replace_greatest_element src/replace_greatest_element.cpp)
add_executable(move_zeros src/move_zeros.cpp)
add_executable(sort_by_parity src/sort_by_parity.cpp)
add_executable(height_checker src/height_checker.cpp)
add_executable(third_max src/third_maximum_number.cpp)
add_executable(find_disappeared src/find_disappeared_numbers.cpp)
add_executable(test_linked_list src/test_linked_list.cpp)

target_link_libraries(test_linked_list
    ${GTEST_LIBRARIES}
    pthread
)