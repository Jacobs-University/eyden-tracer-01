#include "PrimPlane.h"

CPrimPlane::CPrimPlane(const Vec3f &origin, const Vec3f &normal)
        : IPrim(), m_normal(normal), m_origin(origin) {
    normalize(m_normal);
}

CPrimPlane::~CPrimPlane() = default;

bool CPrimPlane::intersect(Ray &ray) const {
// --- PUT YOUR CODE HERE ---
    return false;
}
