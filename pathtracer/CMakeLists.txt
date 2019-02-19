cmake_minimum_required(VERSION 3.12)
project(pathtracer)
set(CMAKE_CXX_STANDARD 17)

add_executable(pathtracer src/main.cc src/Simple.cc src/Simple.hh)

