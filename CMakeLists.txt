cmake_minimum_required(VERSION 3.12)

project(AOC
    VERSION 1.0
    LANGUAGES CXX C)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
# add_compile_options(-Wall -Wextra -pedantic -Wconversion -Werror)

#2022
add_executable(day1_2022 common.cpp 2022/day1.cpp)
add_executable(day1_1_2022 common.cpp 2022/day1_1.cpp)
add_executable(day2_2022 common.cpp 2022/day2.cpp)
add_executable(day2_2_2022 common.cpp 2022/day2_2.cpp)

#2023
add_executable(day1_2023 common.cpp 2023/day1.cpp)
add_executable(day2_2023 common.cpp 2023/day2.cpp)
add_executable(day2_2_2023 common.cpp 2023/day2_2.cpp)
add_executable(day3_2023 common.cpp 2023/day3.cpp)
add_executable(day4_2023 common.cpp 2023/day4.cpp)
add_executable(day5_2023 common.cpp 2023/day5.cpp)
add_executable(day6_2023 common.cpp 2023/day6.cpp)
add_executable(day7_2023 common.cpp 2023/day7.cpp)
