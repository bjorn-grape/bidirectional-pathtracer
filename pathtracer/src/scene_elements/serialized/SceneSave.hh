#pragma once

#include "lights/AllLights.hh"
#include "camera/Camera.hh"
#include "object_path/ObjectPaths.hh"

class SceneSave {
public:

    SceneSave(const AllLights &allLights, const Camera &camera, const std::vector<ObjectPaths> &objects);

    SceneSave() = default;

    const AllLights &getAllLights() const;
    void setAllLights(const AllLights &allLights);

    const Camera &getCamera() const;
    void setCamera(const Camera &camera);

    const std::vector<ObjectPaths> &getObjects() const;
    void setObjects(const std::vector<ObjectPaths> &objects);
    void addObject(const ObjectPaths &object);

    friend class cereal::access;

    template<class Archive>
    void serialize(Archive &ar) {
        ar(CEREAL_NVP(allLights), CEREAL_NVP(camera),
           CEREAL_NVP(objects));
    }

private:
    AllLights allLights;
    Camera camera;
    std::vector<ObjectPaths> objects;

};
