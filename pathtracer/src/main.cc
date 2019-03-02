#include <iostream>
#include "parser/Parser.hh"
#include "scene_elements/fixed_size_vectors/Vector2D.hh"
#include "scene_elements/fixed_size_vectors/Vector3D.hh"
#include "scene_elements/Ray.hh"
#include "scene_elements/serialized/camera/Camera.hh"
#include <cereal/archives/json.hpp>
#include <cereal/types/vector.hpp>
#include <cereal/types/string.hpp>

#include "scene_elements/serialized/object_path/ObjectPaths.hh"

#ifdef  _WIN32
const std::string path_global = "..\\objs\\cube.obj";
#else
const std::string path_global = "../objs/cube.obj";
#endif


Vector3D<float> centerGravityPolygons(std::vector<Polygon> polygons) {
    Vector3D<float> gravityCenter = Vector3D<float>();
    for (size_t i = 0; i < polygons.size(); ++i) {
        gravityCenter += polygons[i].meanVertices();
        std::cout << "center of gravity of " << i << " is " << polygons[i].meanVertices() << "\n";
    }
    gravityCenter /= polygons.size();
    return gravityCenter;
}

void cameraHit() {
    auto list = Parser::fromPathToObjStruct(path_global);
    Camera c = Camera(1.f, Vector2D(512, 512), Vector3D(0.f, 0.0f, -2.f), Vector3D(0.f, 0.f, 1.f), 60);
    //camera c = camera(1.f, Vector2D(512, 512), Vector3D(1.5f, .7f, -1.f), Vector3D(-0.5f, 0.f, 1.f), 90);
    std::cout << "started compute" << std::endl;
    c.computeImage(list);
    std::cout << "end compute" << std::endl;
    c.dumpImageToPpm();
}


int main() {


    //ObjectPaths o3 = vec[0];
    //ObjectPaths o4 = vec[1];


    //Parser::fromPathToObjStruct(path_global);
    return 0;
}
