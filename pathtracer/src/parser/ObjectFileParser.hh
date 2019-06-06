#pragma once


#include<string>
#include "../datastruct/polygon/Polygon.hh"
#include "../scene_elements/serialized/object_path/ObjectPaths.hh"
#include "../datastruct/scene/Scene.hh"

class ObjectFileParser {

public :
    static void
    fromPathToObjStruct(std::string path, Vector3D<float> position,
                        std::vector<Polygon>& polygonVector, std::vector<Material>& materials);

    static void fromAllObjsToObjStruct(const std::vector<ObjectPaths> &objectsPaths, Scene &scene);
};


