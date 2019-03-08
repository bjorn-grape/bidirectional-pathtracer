#pragma once

#include<string>
#include "../scene_elements/Polygon.hh"
#include "../scene_elements/serialized/object_path/ObjectPaths.hh"


class AllPolygonContainer {

public :


    explicit AllPolygonContainer(const std::vector<ObjectPaths> &objectsPaths);

    Polygon operator[](unsigned i) const;

    Polygon at(unsigned i) const;

    std::vector<unsigned> getAllindexes() const;

    std::size_t size() const;

private:
    std::vector<Polygon> fromPathToObjStruct(std::string path,
                                             Vector3D<float> position = Vector3D<float>()) const;

    std::vector<Polygon> polygons_;
};


