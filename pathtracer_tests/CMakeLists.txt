cmake_minimum_required(VERSION 3.12)
project(pathtracer_tests)

set(CMAKE_CXX_STANDARD 17)
SET ( CMAKE_CXX_FLAGS "-Wall -Wextra -pedantic" )

add_executable(pathtracer_tests main.cc tests/vector3dTest.cc tests/serializeTest.cc
        ../pathtracer/src/scene_elements/serialized/object_path/ObjectPaths.cc
        tests/intersectionRayAABBTest.cc ../pathtracer/src/datastruct/box/BoundingBox.cc
        ../pathtracer/src/scene_elements/Ray.cc ../pathtracer/src/scene_elements/Polygon.cc)


include_directories("../pathtracer/src/scene_elements/fixed_size_vectors")
include_directories("../pathtracer/src/scene_elements/serialized")
include_directories("../pathtracer/libs/cereal/include")

include_directories("../pathtracer/src/tools")
include_directories("../pathtracer/src/scene_elements/")
include_directories("../pathtracer/src/datastruct/box")


add_subdirectory("lib/googletest")
include_directories("lib/googletest/googletest/include/")
include_directories("lib/googletest/googlemock/include/")
target_link_libraries(pathtracer_tests gtest gtest_main)
