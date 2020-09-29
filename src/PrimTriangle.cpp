#include "PrimTriangle.h"

CPrimTriangle::CPrimTriangle(const Vec3f &a, const Vec3f &b, const Vec3f &c)
        : IPrim(), m_a(a), m_b(b), m_c(c) {
    m_ab = b - a;
    m_ac = c - a;
}

CPrimTriangle::~CPrimTriangle() = default;

bool CPrimTriangle::intersect(Ray &ray) const {

    return false;
}