#pragma once

#include<string>
#include "../scene_elements/Polygon.hh"
#include "../scene_elements/serialized/object_path/ObjectPaths.hh"


class ObjectFileParser {

public :
    static std::vector<Polygon> fromPathToObjStruct(std::string path,
                                                    Vector3D<float> position = Vector3D<float>());

    static std::vector<Polygon> fromAllObjsToObjStruct(const std::vector<ObjectPaths>& objectsPaths);
};


