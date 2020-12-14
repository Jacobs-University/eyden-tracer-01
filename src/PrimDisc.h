#pragma once

#include "IPrim.h"
#include "ray.h"

// --- IMPLEMENT class CPrimDisc ---
// --- PUT YOUR CODE HERE ---
class CPrimDisc: public IPrim {
public:
    // constructor
    CPrimDisc(const Vec3f& origin, const Vec3f normal, double radius) : IPrim(), m_origin(origin), m_normal(normal), m_radius(radius) {}

    // destructor
    virtual ~CPrimDisc(void) = default;

    // intersect method
    virtual bool intersect(Ray& ray) const override {
        auto plane = CPrimPlane(m_origin, m_normal);
        Ray r_copy = ray;
        if(!plane.intersect(r_copy)) {
            return false;
        }

        auto pt = r_copy.org + r_copy.dir * r_copy.t;
        auto distance = norm(pt - m_origin);
        if(distance > m_radius) {
            return false;
        }

        if(r_copy.t > ray.t) {
            return false;
        }

        ray.t = r_copy.t;
        return true;
    }


private:
    Vec3f m_origin;
    Vec3f m_normal;
    double m_radius;
};
