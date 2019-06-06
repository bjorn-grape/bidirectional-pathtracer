#pragma once

#include <memory>
#include "KDNode.hh"
#include "../polygon/Polygon.hh"
#include "../ray/Ray.hh"

class KDTree {
public:
    KDTree() = default;

    explicit KDTree(std::vector<Polygon> &polygons);

    void getIntersectionList(const Ray &ray, std::vector<Polygon *> &resultList);
    bool getIntersectionPoly(const Ray &ray, Polygon &result) const;

    void printPrefix();

    std::shared_ptr<KDNode> root_ = nullptr;

};
