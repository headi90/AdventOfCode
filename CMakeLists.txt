cmake_minimum_required(VERSION 3.12)

project(AOC
    VERSION 1.0
    LANGUAGES CXX C)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
# add_compile_options(-Wall -Wextra -pedantic -Wconversion -Werror)



add_executable(day1_2023 common.cpp 2023/day1.cpp)
add_executable(day2_2023 common.cpp 2023/day2.cpp)
add_executable(day2_2_2023 common.cpp 2023/day2_2.cpp)
add_executable(day3_2023 common.cpp 2023/day3.cpp)
add_executable(day4_2023 common.cpp 2023/day4.cpp)