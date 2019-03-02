cmake_minimum_required(VERSION 3.12)
project(pathtracer_tests)

set(CMAKE_CXX_STANDARD 17)
SET ( CMAKE_CXX_FLAGS "-Wall -Wextra -pedantic" )

add_executable(pathtracer_tests main.cc tests/vector3dTest.cc tests/serializeTest.cc ../pathtracer/src/scene_elements/serialized/object_path/ObjectPaths.cc)


include_directories("../pathtracer/src/scene_elements/fixed_size_vectors")
include_directories("../pathtracer/src/scene_elements/serialized")
include_directories("../pathtracer/libs/cereal/include")


add_subdirectory("lib/googletest")
include_directories("lib/googletest/googletest/include/")
include_directories("lib/googletest/googlemock/include/")
target_link_libraries(pathtracer_tests gtest gtest_main)
