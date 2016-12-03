cmake_minimum_required(VERSION 3.6)
project(algorithm)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
    ../leetcode/main.cpp ../leetcode/Solution.cpp ../leetcode/Solution.h ../leetcode/Solution_253.cpp ../leetcode/Solution_253.h ../leetcode/Solution_261.cpp ../leetcode/Solution_261.h ../leetcode/Solution_277.cpp ../leetcode/Solution_277.h ../leetcode/Solution_417.cpp ../leetcode/Solution_417.h ../leetcode/Solution_161.cpp ../leetcode/Solution_161.h Solution_356.cpp Solution_356.h Solution_163.cpp Solution_163.h Solution_379.cpp Solution_379.h)

add_executable(algorithm ${SOURCE_FILES})