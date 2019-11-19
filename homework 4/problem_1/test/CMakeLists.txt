add_executable(linked_list_tests main.cpp LinkedListTest.cpp)
add_executable(linked_stack_tests main.cpp LinkedStackTest.cpp)
add_executable(homework_tests main.cpp HomeworkTest.cpp)

include_directories(${CMAKE_LIBRARY_PATH})
link_directories(${LIBRARY_OUTPUT_PATH})

target_link_libraries(
                    linked_list_tests
                    gtest)

target_link_libraries(
        linked_stack_tests
        gtest)

target_link_libraries(
        homework_tests
        gtest)

add_test(
        NAME
        LinkedListUnitTests
        COMMAND
        ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/linked_list_tests
)

add_test(
        NAME
        LinkedStackUnitTests
        COMMAND
        ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/linked_stack_tests
)

add_test(
        NAME
        HomeworkTests
        COMMAND
        ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/homework_tests
)
