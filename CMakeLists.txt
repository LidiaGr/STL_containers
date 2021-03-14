cmake_minimum_required(VERSION 3.17)
project(ft_containers)

set(CMAKE_CXX_STANDARD 98)
add_compile_options( -Wall -Wextra -Werror)

add_subdirectory(googletest)
include_directories(googletest/googletest/include)

add_executable(ft_containers
        srcs/utils.hpp
        srcs/list.hpp unit_tests/listTests.cpp
        srcs/vector.hpp unit_tests/vectorTests.cpp
        srcs/queue.hpp unit_tests/queueTests.cpp
        srcs/stack.hpp unit_tests/stackTests.cpp
        srcs/map.hpp unit_tests/mapTests.cpp
        srcs/set.hpp unit_tests/setTests.cpp
        )

target_link_libraries(ft_containers gtest gtest_main)
