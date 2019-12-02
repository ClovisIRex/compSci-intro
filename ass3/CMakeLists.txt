cmake_minimum_required(VERSION 3.15)
project(ass3 C)

set(CMAKE_C_STANDARD 99)

add_executable(ass3 main.c cmake-build-debug/ass3.c cmake-build-debug/ass3.h)