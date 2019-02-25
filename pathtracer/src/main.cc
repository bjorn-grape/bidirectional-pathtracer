#include <iostream>
#include "parser/Parser.hh"
#include "scene_elements/fixed_size_vectors/Vector2D.hh"
#include "scene_elements/fixed_size_vectors/Vector3D.hh"
#include "scene_elements/Ray.hh"

#ifdef  _WIN32
const std::string path_global = "..\\objs\\cube.obj";
#else
const std::string path_global = "../objs/cube.obj";
#endif

int main() {
    auto v0 = Vector3D<float>(1, 0, 0);
    auto v1 = Vector3D<float>(7, 2, 0);
    auto v2 = Vector3D<float>(4, 3, 0);

    auto point = Vector3D<float>(4, 2, -1);
    auto direc = Vector3D<float>(0, 0, 1);

    auto ray1 = Ray(point, direc);


    std::cout << "res = " << ray1.doIntersect(v0,v1,v2) << std::endl;
    //Parser::fromPathToObjStruct(path_global);
    return 0;
}