//
// Created by bjorn on 25/02/19.
//

#include "Polygon.hh"
#include "../../tools/Tools.hh"


const std::vector<Vector3D<float>> &Polygon::getVertices() const {
    return vertices_;
}

const std::vector<Vector3D<float>> &Polygon::getNormals() const {
    return normals_;
}

const std::vector<Vector2D<float>> &Polygon::getTexcoords() const {
    return texcoords_;
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
    mean_ = meanVertices();
    computeMinMax();
}

std::ostream &operator<<(std::ostream &os, const Polygon &polygon) {
    for (size_t i = 0; i < polygon.size(); ++i) {
        os << "v" << i << ": " << polygon.vertices_[i] << " ";
//       os    << " n" << i << ": " << polygon.normals_[i]
//           << " t" << i << ": " << polygon.texcoords_[i]
//           << " color" << i << ": " << polygon.colors_[i]
//           << "\n";
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
        minx = std::min(minx, vect.getX());
        miny = std::min(miny, vect.getY());
        minz = std::min(minz, vect.getZ());
        maxx = std::max(maxx, vect.getX());
        maxy = std::max(maxy, vect.getY());
        maxz = std::max(maxz, vect.getZ());
    }

    min_ = Vector3D(minx, miny, minz);
    max_ = Vector3D(maxx, maxy, maxz);

}

bool Polygon::operator<(const Polygon &rhs) const {

    return Tools<float>::comparisonFunctionsMap[Polygon::comparisonFactor](this->mean_, rhs.mean_);
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

void Polygon::setComparisonfactor(compFactor comparisonfactor) {
    Polygon::comparisonFactor = comparisonfactor;
}

typename Polygon::compFactor  Polygon::comparisonFactor = compFactor::none;

void Polygon::getBoundsOfInterest(float &min, float &max) const {
    switch (comparisonFactor) {
        case SplitAxis::X :
            min = min_.getX();
            max = max_.getX();
            break;
        case SplitAxis::Y :
            min = min_.getY();
            max = max_.getY();
            break;
        case SplitAxis::Z :
            min = min_.getZ();
            max = max_.getZ();
            break;
    }

}

float Polygon::getMeanOfInterest() const {
    switch (comparisonFactor) {
        case SplitAxis::X :
            return mean_.getX();
        case SplitAxis::Y :
            return mean_.getY();
        case SplitAxis::Z :
            return mean_.getZ();
    }
    throw std::invalid_argument("comparisonFactor not set in polygon");
}

const Material &Polygon::getMaterial() const {
    return material_;
}

void Polygon::setMaterial(const Material &material) {
    material_ = material;
}

Vector3D<float> Polygon::getNormalAt(Vector3D<float> pos) {
    if (isTriangle()) {
//        auto A = vertices_[0];
//        auto B = vertices_[1];
//        auto C = vertices_[2];
//
//        auto AB = B - A;
//        auto AC = C - A;
//        auto AD = pos - A;
//        float u = AB.dotproduct(AD);// / (AB.norm() *AD.norm()) ;
//        float v = AC.dotproduct(AD);/// (AC.norm()*AD.norm());
//        auto N0 = normals_[0];
//        auto N1 = normals_[1];
//        auto N2 = normals_[2];
//        return (1.f - u - v) * N0 + u * N1 + v * N2;


        float dist1 = (vertices_[0] - pos).norm();
        float dist2 = (vertices_[1] - pos).norm();
        float dist3 = (vertices_[2] - pos).norm();
        float sumdist = dist1 + dist2 + dist3;
        dist1 /= sumdist;
        dist2 /= sumdist;
        dist3 /= sumdist;
        dist1 = 1 - dist1;
        dist2 = 1 - dist2;
        dist3 = 1 - dist3;


//        sumdist = dist1 + dist2 + dist3;
//        dist1 /= sumdist;
//        dist2 /= sumdist;
//        dist3 /= sumdist;
        return normals_[0] * dist1 + normals_[1] * dist2 + normals_[2] * dist3;
    }
    std::vector<float> distances;
    float sum = 0.f;
    for (size_t i = 0; i < vertices_.size(); ++i) {
        distances.push_back((pos - vertices_[i]).norm());
        sum += distances[i];
    }
    Vector3D<float> res;
    for (size_t j = 0; j < distances.size(); ++j) {
        float contrib = 1.0f - (distances[j] / sum);
        res += normals_[j] * contrib;
    }
    return res;
}

bool Polygon::operator==(const Polygon &rhs) const {
    return vertices_ == rhs.vertices_ &&
           normals_ == rhs.normals_ &&
           texcoords_ == rhs.texcoords_ &&
           mean_ == rhs.mean_ &&
           min_ == rhs.min_ &&
           max_ == rhs.max_;
}

bool Polygon::operator!=(const Polygon &rhs) const {
    return !(rhs == *this);
}
