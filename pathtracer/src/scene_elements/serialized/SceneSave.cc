//
// Created by bjorn on 02/03/19.
//

#include "SceneSave.hh"

SceneSave::SceneSave(const AllLights &allLights, const Camera &camera, const std::vector<ObjectPaths> &objects)
        : allLights(allLights), camera(camera), objects(objects) {}

const AllLights &SceneSave::getAllLights() const {
    return allLights;
}

void SceneSave::setAllLights(const AllLights &allLights) {
    SceneSave::allLights = allLights;
}

const Camera &SceneSave::getCamera() const {
    return camera;
}

void SceneSave::setCamera(const Camera &camera) {
    SceneSave::camera = camera;
}

const std::vector<ObjectPaths> &SceneSave::getObjects() const {
    return objects;
}

void SceneSave::setObjects(const std::vector<ObjectPaths> &objects) {
    SceneSave::objects = objects;
}
