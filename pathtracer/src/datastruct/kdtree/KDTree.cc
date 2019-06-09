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

void KDTree::getIntersectionList(const Ray &ray, std::vector<PolygonWithIntersection> &resultListWithIntersection) const {
    std::vector<Polygon *>resultList;
    root_->getIntersectionList(ray, resultList);
    for (Polygon *poly: resultList) {
        Vector3D<float> intersect;
        if (ray.intersect(*poly, intersect)) {
            PolygonWithIntersection pppoo = PolygonWithIntersection(poly, intersect);
            resultListWithIntersection.emplace_back(pppoo);
        }
    }
    DistancePolygonComparator disty = DistancePolygonComparator(ray.getPosition());
    std::sort(resultListWithIntersection.begin(), resultListWithIntersection.end(), disty);
}

bool KDTree::getIntersectionPoly(const Ray &ray, Polygon &result) const {
    std::vector<PolygonWithIntersection > pols;
    getIntersectionList(ray, pols);
    if (!pols.empty()) {
        result = *pols[0].polygon;
        return true;
    }
    return false;

}
