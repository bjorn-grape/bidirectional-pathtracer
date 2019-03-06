//
// Created by bjorn on 25/02/19.
//

#include "Polygon.hh"
#include "../tools/Tools.hh"


const std::vector<Vector3D<float>> &Polygon::getVertices() const {
    return vertices_;
}

const std::vector<Vector3D<float>> &Polygon::getNormals() const {
    return normals_;
}

const std::vector<Vector2D<float>> &Polygon::getTexcoords() const {
    return texcoords_;
}

const std::vector<Vector3D<uint8_t>> &Polygon::getColors() const {
    return colors_;
}

bool Polygon::isValid() {
    return vertices_.size() > 2;
}

bool Polygon::isTriangle() const {
    return vertices_.size() == 3;
}

void Polygon::add(const Vector3D<float> &vextex, const Vector3D<float> &normal,
                  const Vector2D<float> &texcoord, const Vector3D<uint8_t> &color) {
    vertices_.emplace_back(vextex);
    normals_.emplace_back(normal);
    texcoords_.emplace_back(texcoord);
    colors_.emplace_back(color);
    mean_ = meanVertices();
    computeMinMax();
}

std::ostream &operator<<(std::ostream &os, const Polygon &polygon) {
    for (size_t i = 0; i < polygon.size(); ++i) {
        os << "v" << i << ": " << polygon.vertices_[i]
           << " n" << i << ": " << polygon.normals_[i]
           << " t" << i << ": " << polygon.texcoords_[i]
           << " color" << i << ": " << polygon.colors_[i]
           << "\n";
    }
    return os;
}

size_t Polygon::size() const {
    return vertices_.size();
}

const Vector3D<float> Polygon::meanVertices() const {
    Vector3D<float> mean = Vector3D<float>();
    for (size_t i = 0; i < vertices_.size(); ++i) {
        mean += getVertices()[i];
    }
    mean /= vertices_.size();
    return mean;
}

void Polygon::computeMinMax() {
    float minx = INFINITY;
    float miny = INFINITY;
    float minz = INFINITY;
    float maxx = -INFINITY;
    float maxy = -INFINITY;
    float maxz = -INFINITY;

    for (const Vector3D<float> &vect: vertices_) {
        minx = std::min(minx,vect.getX());
        miny = std::min(miny,vect.getY());
        minz = std::min(minz,vect.getZ());
        maxx = std::max(maxx,vect.getX());
        maxy = std::max(maxy,vect.getY());
        maxz = std::max(maxz,vect.getZ());
    }

    min_ = Vector3D(minx,miny,minz);
    max_ = Vector3D(maxx,maxy,maxz);

}

bool Polygon::operator<(const Polygon &rhs) const {

    return Tools<float>::comparisonFunctionsMap[Polygon::comparisonFactor](this->mean_,rhs.mean_);
}

bool Polygon::operator>(const Polygon &rhs) const {
    return rhs < *this;
}

bool Polygon::operator<=(const Polygon &rhs) const {
    return !(rhs < *this);
}

bool Polygon::operator>=(const Polygon &rhs) const {
    return !(*this < rhs);
}

void Polygon::setComparisonfactor(SplitAxis::Axis comparisonfactor) {
    Polygon::comparisonFactor = comparisonfactor;
}

typename SplitAxis::Axis  Polygon::comparisonFactor = SplitAxis::none;