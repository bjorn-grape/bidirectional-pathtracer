#include <sstream>
#include <chrono>
#include "KDNode.hh"
#include "../../tools/Tools.hh"
#include "../../tools/performances/Stats.hh"

KDNode::KDNode(std::vector<unsigned> &indexList, AllPolygonContainer &polygons,
               const BoundingBox &box, unsigned depth) {
    /* Constructor initialization */
//    splitAxis_ = box.GetLargestDimension();
    splitAxis_ = box.GetSmallestDimension();
    Polygon::setComparisonfactor(static_cast<Polygon::compFactor>(splitAxis_));
    box_ = std::make_shared<BoundingBox>(box);
    polygons_ = std::make_shared<std::vector<unsigned >>();
//
//    /* End Constructor initialization */
//    if (depth > 5) {
//        for (unsigned index = 0; index < indexList.size(); ++index)
//            polygons_->push_back(indexList[index]);
//        return;
//    }
    double mean = 0.0;
    for (unsigned i = 0; i < indexList.size(); ++i)
        mean += polygons[i].getMeanOfInterest();
    splitValue_ = static_cast<float>(mean / indexList.size());

    auto underList = std::vector<unsigned>();
    auto aboveList = std::vector<unsigned>();
    for (unsigned i = 0; i < indexList.size(); i++) {
        float mmin, mmax;
        polygons[i].getBoundsOfInterest(mmin, mmax);
        if (mmin > splitValue_) {
            aboveList.push_back(indexList[i]);
            continue;
        }
        if (mmax < splitValue_) {
            underList.push_back(indexList[i]);
            continue;
        }
        polygons_->push_back(indexList[i]);
    }
//    if (!underList.empty() || !aboveList.empty()) {
//        for (unsigned index = 0; index < polygons_->size(); ++index) {
//            underList.push_back((*polygons_)[index]);
//            aboveList.push_back((*polygons_)[index]);
//        }
//        polygons_->clear();
//    }

    if (!underList.empty()) {
        BoundingBox b;
        Tools<float>::extremumPolygonList(underList, polygons, b);
        left_ = std::make_shared<KDNode>(underList, polygons, b, depth + 1);
    }

    if (!aboveList.empty()) {
        BoundingBox b;
        Tools<float>::extremumPolygonList(aboveList, polygons, b);
        right_ = std::make_shared<KDNode>(aboveList, polygons, b, depth + 1);
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

void KDNode::getIntersectionList(const Ray &ray, std::unordered_set<unsigned> &resultSet) {
//    auto start = std::chrono::system_clock::now();

    bool res = Tools<float>::IntersectCubeRay(ray, *box_);

//    auto end = std::chrono::system_clock::now();
//    std::chrono::duration<double> elapsed_seconds = end-start;
//    std::time_t end_time = std::chrono::system_clock::to_time_t(end);
//    Stats::AABBvsRay.addTime(elapsed_seconds.count());

    if (res) {
        for (unsigned i = 0; i < polygons_->size(); ++i) {
            resultSet.insert((*polygons_)[i]);
        }
        if (left_ != nullptr)
            left_->getIntersectionList(ray, resultSet);
        if (right_ != nullptr)
            right_->getIntersectionList(ray, resultSet);
    }
}
