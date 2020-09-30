#pragma once

#include "IPrim.h"
#include "ray.h"

// --- IMPLENET class CPrimDisc ---
// --- PUT YOUR CODE HERE ---

class CPrimDisc : public CPrimPlane {

private:
    float m_radius;
public:
    CPrimDisc(const Vec3f& origin, const Vec3f& normal, const float radius)
    : CPrimPlane(origin, normal), m_radius(radius)
    {}

    virtual ~CPrimDisc() = default;

    virtual bool CPrimDisc::intersect(Ray &ray) const {
        float t = (getOrigin() - ray.org).dot(getNormal()) / ray.dir.dot(getNormal());
        if (t < Epsilon || t > ray.t) return false;
        if (norm(ray.org + (ray.dir * t ) - getOrigin()) > m_radius) {
            return false;
        }
        ray.t = t;
        return true;

    }

}
