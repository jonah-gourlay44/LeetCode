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
add_executable(linked_list_cycle src/linked_list_cycle.cpp)
add_executable(linked_list_intersection src/linked_list_intersection.cpp)
add_executable(remove_nth_from_end src/remove_nth_from_end.cpp)
add_executable(reverse_linked_list src/reverse_linked_list.cpp)
add_executable(linked_list_remove_elements src/linked_list_remove_elements.cpp)
add_executable(remove_list_elements src/remove_list_elements.cpp)

target_link_libraries(test_linked_list
    ${GTEST_LIBRARIES}
    pthread
)

target_link_libraries(linked_list_cycle
    ${GTEST_LIBRARIES}
    pthread
)

target_link_libraries(linked_list_intersection
    ${GTEST_LIBRARIES}
    pthread
)

target_link_libraries(remove_nth_from_end
    ${GTEST_LIBRARIES}
    pthread
)

target_link_libraries(reverse_linked_list
    ${GTEST_LIBRARIES}
    pthread
)

target_link_libraries(linked_list_remove_elements
    ${GTEST_LIBRARIES}
    pthread
)

target_link_libraries(remove_list_elements
    ${GTEST_LIBRARIES}
    pthread
)