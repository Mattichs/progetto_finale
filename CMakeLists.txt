cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(battaglia_navale VERSION 1.0)
add_executable(battaglia_navale src/battaglia_navale.cpp src/ship/insert_util.cpp src/player.cpp src/utility.cpp src/ship/ship.cpp src/ship/corazzata.cpp src/ship/empty.cpp src/ship/movement.cpp src/ship/supporto.cpp src/ship/esploratore.cpp src/grid/grid.cpp src/grid/attack_grid.cpp src/grid/defense_grid.cpp)
project(replay VERSION 1.0)
add_executable(replay src/replay.cpp src/player.cpp src/utility.cpp src/ship/insert_util.cpp src/ship/ship.cpp src/ship/corazzata.cpp src/ship/empty.cpp src/ship/movement.cpp src/ship/supporto.cpp src/ship/esploratore.cpp src/grid/grid.cpp src/grid/attack_grid.cpp src/grid/defense_grid.cpp)

target_include_directories(replay PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(battaglia_navale PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
