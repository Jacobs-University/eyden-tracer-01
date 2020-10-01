#include <PrimPlane.h>
#include "PrimDisc.h"

CPrimDisc::CPrimDisc() : IPrim() {
    m_radius = 1;
    m_origin = Vec3f(0, 0, 0);
    m_normal = Vec3f(0, 1, 0);
}

CPrimDisc::CPrimDisc(const Vec3f& origin, const Vec3f& normal, double radius) : IPrim(), m_origin(origin), m_normal(normal), m_radius(radius)
{
}

CPrimDisc::~CPrimDisc() = default;

Vec3f CPrimDisc::getNormal() const{
    return m_normal;
}

Vec3f CPrimDisc::getOrigin() const {
    return m_origin;
}

double CPrimDisc::getRadius() const {
    return m_radius;
}

bool CPrimDisc::intersect(Ray &ray) const {
    auto plane = CPrimPlane(m_origin, m_normal);
    // we copy the given ray to make sure we don't
    // modify the value in case of failure.
    Ray rayCpy = ray;
    if (!plane.intersect(rayCpy))
        return false;
    auto pt = rayCpy.org + rayCpy.dir*rayCpy.t;
    auto d = norm(pt - m_origin);
    if (d > m_radius)
        return false;
    if (rayCpy.t > ray.t)
        return false;
    ray.t = rayCpy.t;
    return true;
}
