#pragma once

#include <memory>
#include "KDNode.hh"
#include "../../scene_elements/Polygon.hh"
#include "../../scene_elements/Ray.hh"
#include "../../parser/AllPolygonContainer.hh"

class KDTree {
public:

    KDTree( AllPolygonContainer& polygons);

    void getIntersectionList(const Ray& ray, std::unordered_set<unsigned> &resultList);

    void printPrefix();
    std::shared_ptr<KDNode> root_ = nullptr;

};
