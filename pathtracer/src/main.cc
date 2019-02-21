#include <iostream>
#include "parser/Parser.hh"
#include "scene_elements/fixed_size_vectors/Vector2D.hh"

#ifdef  _WIN32
const std::string path_global = "..\\objs\\cube.obj";
#else
const std::string path_global = "../objs/cube.obj";
#endif

int main() {
    auto a = Vector2D<float>(2.f, 2.f);
    auto b = Vector2D<float>(1.f, 5.f);
    std::cout << "test" << (a.dotproduct(b))  << std::endl;
    //Parser::fromPathToObjStruct(path_global);
    return 0;
}