#pragma once

#include <memory>
#include "KDNode.hh"
#include "Polygon.hh"
#include "../ray/Ray.hh"
#include "PolygonWithIntersection.hh"

class KDTree {
public:
    KDTree() = default;

    explicit KDTree(std::vector<Polygon> &polygons);

    void getIntersectionList(const Ray &ray, std::vector<PolygonWithIntersection> &resultList) const;
    bool getIntersectionPoly(const Ray &ray, Polygon &result) const;

    void printPrefix();

    std::shared_ptr<KDNode> root_ = nullptr;

};
