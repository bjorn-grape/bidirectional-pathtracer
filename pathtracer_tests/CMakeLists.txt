cmake_minimum_required(VERSION 3.12)
project(pathtracer_tests)

set(CMAKE_CXX_STANDARD 17)

add_executable(pathtracer_tests main.cc)


add_subdirectory("lib/googletest")
include_directories("lib/googletest/googletest/include/")
include_directories("lib/googletest/googlemock/include/")
target_link_libraries(pathtracer_tests gtest gtest_main)
