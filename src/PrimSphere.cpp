#include "PrimSphere.h"

CPrimSphere::CPrimSphere(const Vec3f &origin, float radius)
        : IPrim(), m_origin(origin), m_radius(radius) {}

CPrimSphere::~CPrimSphere() = default;

bool CPrimSphere::intersect(Ray &ray) const {
    // Add my code here.
    return false;
}
