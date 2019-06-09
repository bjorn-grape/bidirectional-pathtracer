#include <memory>
#include <polygon/PolygonWithIntersection.hh>
#include <DistancePolygonComparator.hh>

#include "KDTree.hh"
#include "../../tools/Tools.hh"

KDTree::KDTree(std::vector<Polygon> &polygons) {
    if (root_ != nullptr) {
        std::cerr << "KDTree not empty !" << std::endl;
        return;
    }
    BoundingBox b;
    b.setExtremumFromPolygonList(polygons);
    root_ = std::make_shared<KDNode>(polygons, b, 0);
}

void KDTree::printPrefix() {
    if (!root_) {
        std::cerr << "No Tree" << std::endl;
        return;
    }
    root_->printInfix(1, true);

}

void KDTree::getIntersectionList(const Ray &ray, std::vector<Polygon *> &resultList) {
    root_->getIntersectionList(ray, resultList);
    std::vector<PolygonWithIntersection> temp_array;
    for (Polygon *poly: resultList) {
        Vector3D<float> intersect;
        if (ray.intersect(*poly, intersect)) {
            auto pppoo = PolygonWithIntersection(poly, intersect);
            temp_array.emplace_back(pppoo);
        }
    }
    DistancePolygonComparator disty = DistancePolygonComparator(ray.getPosition());
    std::sort(temp_array.begin(),temp_array.end(), disty);
    resultList.clear();
    for(PolygonWithIntersection poly: temp_array){
       Polygon* p = poly.polygon;
        resultList.emplace_back(p);
    }

}

bool KDTree::getIntersectionPoly(const Ray &ray, Polygon &result) const {
    float dist = INFINITY;
    root_->getIntersectionPolygon(ray, result, dist);
    return dist != INFINITY;
}
