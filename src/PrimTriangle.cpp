#include "PrimTriangle.h"

CPrimTriangle::CPrimTriangle(const Vec3f &a, const Vec3f &b, const Vec3f &c)
        : IPrim(), m_a(a), m_b(b), m_c(c) {
    m_ab = b - a;
    m_ac = c - a;
}

CPrimTriangle::~CPrimTriangle() = default;

bool CPrimTriangle::intersect(Ray &ray) const {
    auto P = ray.dir.cross(m_ac);
    auto T = ray.org - m_a;
    auto det = P.dot(m_ab);
    if (abs(det) < Epsilon)
        return false;
    auto Q = T.cross(m_ab);
    auto u = P.dot(T) * (1/det);
    if (u < 0.0f || u > 1.0f)
        return false;
    auto v = Q.dot(ray.dir)*(1/det);
    if (v < 0.0f || u + v > 1.0f)
        return false;
    auto t = Q.dot(m_ac)* (1/det);
    if (ray.t <= t || t < Epsilon)
        return false;

    ray.t = t;
    return true;
}