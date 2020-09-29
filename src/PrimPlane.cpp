#include "PrimPlane.h"

CPrimPlane::CPrimPlane(const Vec3f &origin, const Vec3f &normal)
        : IPrim(), m_normal(normal), m_origin(origin) {
    normalize(m_normal);
}

CPrimPlane::~CPrimPlane() = default;

bool CPrimPlane::intersect(Ray &ray) const {
    auto d = (m_origin - ray.org).dot(m_normal) / ray.dir.dot(m_normal);
    if (d < Epsilon || d > std::numeric_limits<float>::max())
        return false;
    ray.t = d;
    return true;
}
