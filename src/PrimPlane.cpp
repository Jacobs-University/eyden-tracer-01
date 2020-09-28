#include "PrimPlane.h"

CPrimPlane::CPrimPlane(const Vec3f &origin, const Vec3f &normal)
        : IPrim(), m_normal(normal), m_origin(origin) {
    normalize(m_normal);
}

CPrimPlane::~CPrimPlane() = default;

bool CPrimPlane::intersect(Ray &ray) const {
    auto a = (m_origin - ray.org).dot(m_normal);
    auto b = ray.dir.dot(m_normal);
    if (b < Epsilon)
        return false;
    if (a < Epsilon)
        return false;
    ray.dir = a / b;
    return true;
}
