#pragma once

#include <serialized/scene_type/RenderType.hh>
#include "lights/AllLights.hh"
#include "camera/Camera.hh"
#include "object_path/ObjectPaths.hh"

class SceneSave {
public:

    SceneSave(const AllLights &allLights, const Camera &camera, const std::vector<ObjectPaths> &objects);

    SceneSave() = default;

    const AllLights &getAllLights() const;
    void setAllLights(const AllLights &allLights);

    Camera &getCamera();
    void setCamera(const Camera &camera);
    void setRenderType(const RenderType &rd_type);

    const std::vector<ObjectPaths> &getObjects() const;
    void setObjects(const std::vector<ObjectPaths> &objects);
    void addObject(const ObjectPaths &object);

    friend class cereal::access;

    template<class Archive>
    void serialize(Archive &ar) {
        ar(CEREAL_NVP(all_lights_), CEREAL_NVP(camera_),
           CEREAL_NVP(objects_),CEREAL_NVP(rd_type_));
    }

    RenderType getRenderType();

private:
    AllLights all_lights_;
    Camera camera_;
    std::vector<ObjectPaths> objects_;
    RenderType rd_type_;

};
