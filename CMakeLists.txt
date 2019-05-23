cmake_minimum_required(VERSION 3.14)
project(fp_in_cpp)

set(CMAKE_CXX_STANDARD 17)

find_package(range-v3 REQUIRED)
#add_executable(rangetest main.cpp)
#target_link_libraries(rangetest ::range-v3)
include_directories(/usr/local/include)

add_executable(fp_in_cpp main.cpp)

add_subdirectory(src)