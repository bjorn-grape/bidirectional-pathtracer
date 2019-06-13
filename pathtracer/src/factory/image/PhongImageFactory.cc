#include <cereal/types/string.hpp>
#include <Colors.hh>
#include "Camera.hh"
#include "PhongImageFactory.hh"

PhongImageFactory::PhongImageFactory(const Camera &cam, const Scene &scene)
        : ImageFactory(cam, scene) {}

void PhongImageFactory::computePixel(const Ray &ray, Vector3D<float> &cool) const {
    Polygon intersect_poly;
    bool hit = scene_.kdtree.getIntersectionPoly(ray, intersect_poly);


    if (hit) {
        Vector3D<float> intersectionPoint;
        ray.intersect(intersect_poly, intersectionPoint);
        Vector3D<float> N = intersect_poly.getNormalAt(intersectionPoint);
//        for (int i = 0; i < 3; ++i) {
//            N += intersect_poly.getNormals()[i];
//        }
//        N /= 3;
        Vector3D<float> Ks = Vector3D(intersect_poly.getMaterial().specular);
        Vector3D<float> Kd = Vector3D(intersect_poly.getMaterial().diffuse);
        Vector3D<float> Ka = Vector3D(intersect_poly.getMaterial().ambient);
        float Alpha = intersect_poly.getMaterial().shininess;
        Vector3D<float> V = ray.getDirection() * -1;

        Vector3D<float> Ia = scene_.allLights.ambient_lights_[0].getColor_();

        Vector3D<float> Ip = Ka * Ia;
//
        for (const auto &light: scene_.allLights.directional_lights_) {
//            Ray lir = Ray(intersectionPoint,light.getDirection());
//            Polygon firstIntersectionPoly;
//            scene.kdtree.getIntersectionPoly(lir, firstIntersectionPoly);
//            if(firstIntersectionPoly != intersect_poly){
//                continue;
//            }

            Vector3D<float> Lm = light.getDirection() * -1;
            Vector3D<float> Rm = 2.f * (Lm.dotproduct(N)) * N - Lm;
            Vector3D<float> Id = light.getColor_();
            Ip += Kd * (Lm.dotproduct(N)) * Id + (Ks * Rm.dotproduct(V)).power(2.f) * 0.05f;
        }

        float R = std::max(0.f, std::min(Ip.getX(), 1.f));
        float G = std::max(0.f, std::min(Ip.getY(), 1.f));
        float B = std::max(0.f, std::min(Ip.getZ(), 1.f));
        cool = Vector3D<float>(R, G, B);
    } else
        cool = Colors::DARKGREY ;

}

void PhongImageFactory::compute() {

    travelScreen(0);
}
