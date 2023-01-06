cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(test VERSION 1.0)
add_executable(test src/grids_test.cpp src/ship/ship.cpp src/ship/corazzata.cpp src/ship/movement.cpp src/ship/supporto.cpp src/ship/esploratore.cpp src/grid/grid.cpp src/grid/attack_grid.cpp src/grid/defense_grid.cpp)
target_include_directories(test PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
