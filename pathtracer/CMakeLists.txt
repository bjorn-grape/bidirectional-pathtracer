cmake_minimum_required(VERSION 3.12)
project(pathtracer)
set(CMAKE_CXX_STANDARD 17)

add_executable(pathtracer src/main.cc src/Simple.cc src/Simple.hh src/parser/Parser.cc src/parser/Parser.hh src/scene_elements/lights/ambient_light.cc src/scene_elements/lights/ambient_light.hh src/scene_elements/obervers.cc src/scene_elements/obervers.hh src/scene_elements/objects_3d.cc src/scene_elements/objects_3d.hh src/scene_elements/lights/point_light.cc src/scene_elements/lights/point_light.hh src/scene_elements/fixed_size_vectors/vector3D.cc src/scene_elements/fixed_size_vectors/vector3D.hh)

