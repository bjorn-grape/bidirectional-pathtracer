#include <cereal/archives/json.hpp>
#include <cereal/types/vector.hpp>
#include <cereal/types/string.hpp>
#include "Executor.hh"
#include "../scene_elements/fixed_size_vectors/Vector3D.hh"
#include "../scene_elements/Polygon.hh"
#include "../parser/ObjectFileParser.hh"
#include "../scene_elements/serialized/camera/Camera.hh"
#include "../parser/SaveManager.hh"
#include "../factory/SceneFactory.hh"

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
    auto list = ObjectFileParser::fromPathToObjStruct(path_global);
    Camera c = Camera(1.f, Vector2D(512, 512), Vector3D(1.5f, .7f, -1.f), Vector3D(-0.5f, 0.f, 1.f), 90);
    std::cout << "started compute" << std::endl;
    c.computeImage(list);
    std::cout << "end compute" << std::endl;
    c.dumpImageToPpm();
}

void cameraHit2() {
    auto list = ObjectFileParser::fromPathToObjStruct(path_global);
    Camera c = Camera(1.f, Vector2D(512, 512), Vector3D(0.f, 0.0f, -2.f), Vector3D(0.f, 0.f, 1.f), 60);
    std::cout << "started compute" << std::endl;
    c.computeImage(list);
    std::cout << "end compute" << std::endl;
    c.dumpImageToPpm();
}

void Executor::load(const std::string &path) {
    SaveManager::Load(path, sceneSave_);
}

void Executor::save(const std::string &path) {
    SaveManager::Save(path, sceneSave_);
}

void Executor::setType(Executor::jobType type) {
    type_ = type;
}

void Executor::run() {
    map_actions[type_]();
}

Executor::Executor() {
    map_actions[jobType::none] = [](){};
    map_actions[jobType::binaryTest] = cameraHit;
    map_actions[jobType::binaryTest2] = cameraHit2;
    map_actions[jobType::buildscene] = [](){ SceneFactory::BuildScene();};
}

