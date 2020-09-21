#include "PrimTriangle.h"

CPrimTriangle::CPrimTriangle(const Vec3f &a, const Vec3f &b, const Vec3f &c)
        : IPrim(), m_a(a), m_b(b), m_c(c) {}

CPrimTriangle::~CPrimTriangle() = default;

bool CPrimTriangle::intersect(Ray &ray) const {
    // --- PUT YOUR CODE HERE ---
    return false;
}