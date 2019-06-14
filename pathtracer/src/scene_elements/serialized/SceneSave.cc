//
// Created by bjorn on 02/03/19.
//

#include "SceneSave.hh"

SceneSave::SceneSave(const AllLights &allLights, const Camera &camera, const std::vector<ObjectPaths> &objects)
        : all_lights_(allLights), camera_(camera), objects_(objects) {}

const AllLights &SceneSave::getAllLights() const {
    return all_lights_;
}

void SceneSave::setAllLights(const AllLights &allLights) {
    SceneSave::all_lights_ = allLights;
}

Camera &SceneSave::getCamera() {
    return camera_;
}

void SceneSave::setCamera(const Camera &camera) {
    SceneSave::camera_ = camera;
}

const std::vector<ObjectPaths> &SceneSave::getObjects() const {
    return objects_;
}

void SceneSave::setObjects(const std::vector<ObjectPaths> &objects) {
    SceneSave::objects_ = objects;
}

void SceneSave::addObject(const ObjectPaths &object) {
    objects_.emplace_back(object);
}

void SceneSave::setRenderType(const RenderType &rd_type) {
    rd_type_ = rd_type;
}

RenderType SceneSave::getRenderType() {
    return rd_type_;
}
