cmake_minimum_required(VERSION 3.8)	 # Проверка версии CMake.    										
project(game)			# Название проекта

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES main.cpp Tank.h Map.h Bullet.h)
add_executable(game ${SOURCE_FILES})
target_link_libraries(game sfml-system sfml-graphics sfml-window)
