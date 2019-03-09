#pragma once

#include <string>
#include "../scene_elements/Polygon.hh"
#include "../scene_elements/serialized/object_path/ObjectPaths.hh"


class AllPolygonContainer {

public :


    explicit AllPolygonContainer(const std::vector<ObjectPaths> &objectsPaths);

    inline Polygon operator[](unsigned i) const;

    inline Polygon at(unsigned i) const;

    inline std::vector<unsigned> getAllindexes() const;

    inline std::size_t size() const;

private:
    std::vector<Polygon> fromPathToObjStruct(std::string path,
                                             Vector3D<float> position = Vector3D<float>());

    std::vector<Polygon> polygons_;
};

#include "AllPolygonContainer.hxx"
