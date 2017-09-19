cmake_minimum_required(VERSION 3.8)
project(workshops_c)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c)
add_executable(workshops_c ${SOURCE_FILES})
add_executable(exercise1-1-1 workshop1/exercise1/exercise1-1-1.c)
add_executable(clocktest workshop1/exercise2/clocktest.c)
add_executable(exercise1-1-2 workshop1/exercise1/exercise1-1-2.c)
add_executable(exercise1-1-3 workshop1/exercise1/exercise1-1-3.c)
add_executable(exercise1-1-4 workshop1/exercise1/exercise1-1-4.c)
add_executable(exercise1-1-5 workshop1/exercise1/exercise1-1-5.c)