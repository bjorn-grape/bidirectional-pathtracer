//
// Created by bjorn on 13/03/19.
//

#ifndef PATHTRACER_POLYGONDIST_HH
#define PATHTRACER_POLYGONDIST_HH


#include "../../scene_elements/Polygon.hh"

class PolygonDist {

public:
    PolygonDist(float distance, const Polygon &polygon);

    bool operator<(const PolygonDist &rhs) const;

    bool operator>(const PolygonDist &rhs) const;

    bool operator<=(const PolygonDist &rhs) const;

    bool operator>=(const PolygonDist &rhs) const;

    const Polygon& getPolygon() const;
private:
    float distance;
    Polygon polygon;
};


#endif //PATHTRACER_POLYGONDIST_HH
