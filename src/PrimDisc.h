#pragma once

#include "IPrim.h"
#include "ray.h"
#include "PrimPlane.h"

// --- IMPLENET class CPrimDisc ---
// --- PUT YOUR CODE HERE ---

class CPrimDisc : public IPrim {
public:

 
    CPrimDisc(const Vec3f& origin, const Vec3f& normal, double radius)
        : IPrim(),
        m_origin(origin),
        m_normal(normal),
        m_radius(radius)
    {}

    virtual ~CPrimDisc(void) = default;


    virtual bool intersect(Ray& ray) const override
    {
        auto plane = CPrimPlane(m_origin, m_normal);
    
        Ray rayCpy = ray;
        if (!plane.intersect(rayCpy))
            return false;
        auto pt = rayCpy.org + rayCpy.dir * rayCpy.t;
        auto d = norm(pt - m_origin);
        if (d > m_radius)
            return false;
        if (rayCpy.t > ray.t)
            return false;
        ray.t = rayCpy.t;
        return true;
    }

private:
    Vec3f m_origin;
    Vec3f m_normal;
    double m_radius;
};