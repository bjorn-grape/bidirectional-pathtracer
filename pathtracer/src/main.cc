#include <iostream>
#include "parser/Parser.hh"
#include "scene_elements/fixed_size_vectors/Vector2D.hh"
#include "scene_elements/fixed_size_vectors/Vector3D.hh"

#ifdef  _WIN32
const std::string path_global = "..\\objs\\cube.obj";
#else
const std::string path_global = "../objs/cube.obj";
#endif

int main() {
    auto a = Vector3D<float>(2.f, 2.f,3.f);
    auto b = Vector3D<float>(1.f, 5.f, 4.f);
   // a *= a;
    //a /=a;
    a += 2.f * a;
    //a -=a;


    std::cout << "test" << (a)  << std::endl;
    //Parser::fromPathToObjStruct(path_global);
    return 0;
}