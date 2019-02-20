cmake_minimum_required(VERSION 3.12)
project(pathtracer)
set(CMAKE_CXX_STANDARD 17)

add_executable(pathtracer src/main.cc src/Simple.cc src/Simple.hh src/parser/Parser.cc src/parser/Parser.hh src/scene_elements/lights/ambientLight.cc src/scene_elements/lights/ambientLight.hh src/scene_elements/obervers.cc src/scene_elements/obervers.hh src/scene_elements/objects3d.cc src/scene_elements/objects3d.hh src/scene_elements/lights/pointLight.cc src/scene_elements/lights/pointLight.hh src/scene_elements/fixed_size_vectors/vector3D.hxx src/scene_elements/fixed_size_vectors/vector3D.hh src/scene_elements/fixed_size_vectors/vector2D.hxx src/scene_elements/fixed_size_vectors/vector2D.hh)

