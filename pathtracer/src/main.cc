#include <iostream>
#include "parser/Parser.hh"
#include "scene_elements/fixed_size_vectors/Vector2D.hh"
#include "scene_elements/fixed_size_vectors/Vector3D.hh"
#include "scene_elements/Ray.hh"
#include "scene_elements/Camera.hh"

#ifdef  _WIN32
const std::string path_global = "..\\objs\\cube.obj";
#else
const std::string path_global = "../objs/cube.obj";
#endif

void vectorTest() {
    auto v0 = Vector3D<float>(1, 0, 0);
    auto v1 = Vector3D<float>(7, 2, 0);
    auto v2 = Vector3D<float>(4, 3, 0);

    auto point = Vector3D<float>(4, 3, 0.1f);
    auto direc = Vector3D<float>(-1, -1, -1);

    auto ray1 = Ray(point, direc);

    auto intersec = Vector3D<float>();

    std::cout << "res = " << ray1.intersectOneTriangle(v0, v1, v2, intersec)
              << " and intesection is " << intersec << std::endl;
}

int main() {
    auto list = Parser::fromPathToObjStruct(path_global);
    /*for (int i = 0; i < list.size(); ++i) {
        std::cout << list[i] << "\n";
    }*/
    Camera c = Camera(1.f, Vector2D(200, 400), Vector3D(-5.f, 0.f, 0.f), Vector3D(1.f, 0.f, 0.f));
    std::cout << "started compute" << std::endl;
    c.computeImage(list);
    std::cout << "end compute" << std::endl;

    c.dumpImageToPpm();

    //Parser::fromPathToObjStruct(path_global);
    return 0;
}
