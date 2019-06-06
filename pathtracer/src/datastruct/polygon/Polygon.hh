#pragma once


#include <vector>
#include <ostream>
#include "Vector3D.hh"
#include "Vector2D.hh"
#include "SplitAxis.hh"
#include "Material.hh"

class Polygon {
public:
    enum compFactor {
        none = 0, X = 1, Y = 2, Z = 4, distanceToOrigin = 8
    };

    void add(const Vector3D<float> &vextex, const Vector3D<float> &normal,
             const Vector2D<float> &texcoord, const Vector3D<uint8_t> &color);

    const std::vector<Vector3D<float>> &getVertices() const;

    const std::vector<Vector3D<float>> &getNormals() const;

    const std::vector<Vector2D<float>> &getTexcoords() const;


    const Vector3D<float> meanVertices() const;

    bool isValid();

    bool isTriangle() const;

    size_t size() const;

    friend std::ostream &operator<<(std::ostream &os, const Polygon &polygon);

    bool operator<(const Polygon &rhs) const;

    bool operator>(const Polygon &rhs) const;

    bool operator<=(const Polygon &rhs) const;

    bool operator>=(const Polygon &rhs) const;

    void getBoundsOfInterest(float &min, float &max) const;

    float getMeanOfInterest() const;

    const Material &getMaterial() const;

    void setMaterial(const Material &material);

    Vector3D<float> getNormalAt(Vector3D<float> pos);

    static void setComparisonfactor(compFactor comparisonfactor);

    static compFactor comparisonFactor; //should be changed but not sure how
    bool operator==(const Polygon &rhs) const;

    bool operator!=(const Polygon &rhs) const;

private:
    void computeMinMax();
    std::vector<Vector3D<float>> vertices_;
    std::vector<Vector3D<float>> normals_;
    std::vector<Vector2D<float>> texcoords_;
    Vector3D<float> mean_;
    Vector3D<float> min_;
    Vector3D<float> max_;
    Material material_;
};

#include "Polygon.hxx"