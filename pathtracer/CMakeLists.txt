cmake_minimum_required(VERSION 3.12)
project(pathtracer)
set(CMAKE_CXX_STANDARD 17)
SET ( CMAKE_CXX_FLAGS "-Wall -Wextra -pedantic -Werror" )

add_executable(pathtracer src/main.cc src/Simple.cc src/Simple.hh src/parser/Parser.cc src/parser/Parser.hh src/scene_elements/lights/AmbientLight.cc src/scene_elements/lights/AmbientLight.hh src/scene_elements/lights/PointLight.cc src/scene_elements/lights/PointLight.hh src/scene_elements/fixed_size_vectors/Vector3D.hxx src/scene_elements/fixed_size_vectors/Vector3D.hh src/scene_elements/fixed_size_vectors/Vector2D.hxx src/scene_elements/fixed_size_vectors/Vector2D.hh src/scene_elements/lights/DirectionalLight.cc src/scene_elements/lights/DirectionalLight.hh src/scene_elements/lights/SpotLight.cc src/scene_elements/lights/SpotLight.hh src/scene_elements/lights/Light.cc src/scene_elements/lights/Light.hh src/scene_elements/fixed_size_vectors/Constants.hh src/scene_elements/Ray.cc src/scene_elements/Ray.hh src/maths/Matrix.hxx src/maths/Matrix.hh src/scene_elements/Polygon.cc src/scene_elements/Polygon.hh src/scene_elements/fixed_size_vectors/Vector2D.cc src/scene_elements/Camera.cc src/scene_elements/Camera.hh src/scene_elements/LuminanceInPoint.cc src/scene_elements/LuminanceInPoint.hh)

