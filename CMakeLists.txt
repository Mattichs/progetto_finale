cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(test VERSION 1.0)
add_executable(test src/main.cpp src/ship.cpp src/corazzata.cpp src/movement.cpp)
target_include_directories(test PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
