#include <sstream>
#include <chrono>
#include "KDNode.hh"
#include "../../tools/Tools.hh"
#include "../../tools/performances/Stats.hh"

KDNode::KDNode(std::vector<Polygon> &polygonsVect, const BoundingBox &box, const unsigned depth) {
    /* Constructor initialization */
    unsigned moddepth = depth % 3;
    switch (moddepth) {
        case 0:
            splitAxis_ = SplitAxis::X;
            break;
        case 1:
            splitAxis_ = SplitAxis::Y;
            break;
        default:
            splitAxis_ = SplitAxis::Z;
            break;
    }
    Polygon::setComparisonfactor(static_cast<Polygon::compFactor>(splitAxis_));
    box_ = std::make_shared<BoundingBox>(box);
    polygons_ = std::make_shared<std::vector<Polygon>>();

    /* End Constructor initialization */
    std::sort(polygonsVect.begin(), polygonsVect.end());
    splitValue_ = polygonsVect[polygonsVect.size() / 2].getMeanOfInterest();

    auto underList = std::vector<Polygon>();
    auto aboveList = std::vector<Polygon>();
    for (const auto &polygon: polygonsVect) {
        float mmin, mmax;
        polygon.getBoundsOfInterest(mmin, mmax);
        if (mmin > splitValue_) {
            aboveList.push_back(polygon);
            continue;
        }
        if (mmax < splitValue_) {
            underList.push_back(polygon);
            continue;
        }
        polygons_->push_back(polygon);
    }

    if (!underList.empty()) {
        BoundingBox b;
        b.setExtremumFromPolygonList(underList);
        left_ = std::make_shared<KDNode>(underList, b, depth + 1);

    }
    if (!aboveList.empty()) {
        BoundingBox b;
        b.setExtremumFromPolygonList(aboveList);
        right_ = std::make_shared<KDNode>(aboveList, b, depth + 1);
    }


}

void KDNode::printInfix(unsigned id, bool isleft) {

    std::ostringstream nodeName("");


    nodeName << "id:" << id << " ";

    switch (splitAxis_) {
        case SplitAxis::X :
            nodeName << "X";
            break;
        case SplitAxis::Y :
            nodeName << "Y";
            break;
        case SplitAxis::Z :
            nodeName << "Z";
            break;
        default:
            nodeName << "none";
    }
    nodeName << " val:" << splitValue_ << " size:" << polygons_->size();

    std::string name = "\"" + nodeName.str() + "\"";
    if (id > 0)
        std::cout << name << ";\n";

    if (left_) {
        std::cout << name << " -> ";
        left_->printInfix(id * 2, true);
    }

    if (right_) {
        std::cout << name << " -> ";
        right_->printInfix(id * 2 + 1, false);
    }

}

void KDNode::getIntersectionList(const Ray &ray, std::vector<Polygon *> &resultList) {
//    auto start = std::chrono::system_clock::now();

    bool res = box_->FasterDoIntersect(ray);
    if (res) {
        for (Polygon &poly: *polygons_) {
            resultList.emplace_back(&poly);
        }
        if (left_ != nullptr)
            left_->getIntersectionList(ray, resultList);
        if (right_ != nullptr)
            right_->getIntersectionList(ray, resultList);
    }

}

void KDNode::getIntersectionPolygon(const Ray &ray, Polygon &result, float &minDistance) {
    bool res = box_->FasterDoIntersect(ray);
    if (res) {
        for (Polygon &poly: *polygons_) {
            Vector3D<float> intersectionPoint;
            if (ray.intersect(poly, intersectionPoint)) {
                float tmpdist = (ray.getPosition() - intersectionPoint).norm();
                if (tmpdist < minDistance) {
                    minDistance = tmpdist;
                    result = poly;
                }
            }
        }
        if (left_ != nullptr)
            left_->getIntersectionPolygon(ray, result, minDistance);
        if (right_ != nullptr)
            right_->getIntersectionPolygon(ray, result, minDistance);
    }
}
