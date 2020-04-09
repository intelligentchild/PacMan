cmake_minimum_required(VERSION 3.7)

add_definitions(-std=c++17)

set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")

project(PacMan)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS} src)

# for arch SDL2 LIBRARIES
#IF (${SDL2_LIBRARIES})
#   MESSAGE(STATUS "Found SDL2.")
#ELSE (${SDL2_LIBRARIES})
#    MESSAGE(STATUS "Finding SDL2 using PkgConfig.")
#    find_package(PkgConfig REQUIRED)
#    pkg_check_modules(SDL2 REQUIRED sdl2)
#ENDIF (${SDL2_LIBRARIES})

add_executable(PacManGame src/main.cpp src/game.cpp src/controller.h src/renderer.cpp src/layout.cpp src/gameState.cpp src/agent.cpp src/pacman.cpp src/ghost.cpp)
string(STRIP ${SDL2_LIBRARIES} SDL2_LIBRARIES)
target_link_libraries(PacManGame ${SDL2_LIBRARIES})
