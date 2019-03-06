#pragma once


#include <vector>
#include <ostream>
#include "fixed_size_vectors/Vector3D.hh"
#include "fixed_size_vectors/Vector2D.hh"
#include "../datastruct/SplitAxis.hh"

class Polygon {
public:
    void add(const Vector3D<float> &vextex, const Vector3D<float> &normal,
             const Vector2D<float> &texcoord, const Vector3D<uint8_t> &color);

    const std::vector<Vector3D<float>> &getVertices() const;

    const std::vector<Vector3D<float>> &getNormals() const;

    const std::vector<Vector2D<float>> &getTexcoords() const;

    const std::vector<Vector3D<uint8_t>> &getColors() const;

    const Vector3D<float> meanVertices() const;

    bool isValid();

    bool isTriangle() const;

    size_t size() const;

    friend std::ostream &operator<<(std::ostream &os, const Polygon &polygon);

    bool operator<(const Polygon &rhs) const;

    bool operator>(const Polygon &rhs) const;

    bool operator<=(const Polygon &rhs) const;

    bool operator>=(const Polygon &rhs) const;

    static void setComparisonfactor(SplitAxis::Axis comparisonfactor);

    static SplitAxis::Axis comparisonFactor;

private:
    void computeMinMax();

    std::vector<Vector3D<float>> vertices_;
    std::vector<Vector3D<float>> normals_;
    std::vector<Vector2D<float>> texcoords_;
    std::vector<Vector3D<uint8_t>> colors_;
    Vector3D<float> mean_;
    Vector3D<float> min_;
    Vector3D<float> max_;

};

#include "Polygon.hxx"