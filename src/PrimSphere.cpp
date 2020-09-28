#include "PrimSphere.h"

CPrimSphere::CPrimSphere(const Vec3f &origin, float radius)
        : IPrim(), m_origin(origin), m_radius(radius) {}

CPrimSphere::~CPrimSphere() = default;

bool CPrimSphere::intersect(Ray &ray) const {
    const float max = std::numeric_limits<float>::max();
    auto L = m_origin - ray.org;
    auto delta = pow(2*ray.dir.dot(L), 2) - 4*(pow(norm(L), 2) - pow(m_radius, 2));

    if (delta < 0){
        return false;
    }
    else if (delta == 0){
        auto x = 2*ray.dir.dot(L);
        if (x > Epsilon && x < max){
            ray.dir = x;
            return true;
        }
    }
    else
    {
        auto x1 = ray.dir.dot(L) + (sqrt(delta) / 2);
        auto x2 = ray.dir.dot(L) - (sqrt(delta) / 2);
        if (x1 < x2)
        {
            if (x1 > Epsilon && x1 < max)
            {
                ray.dir = x1;
                return true;
            }
            return false;
        } else {
            if (x2 > Epsilon && x2 < max)
            {
                ray.dir = x2;
                return true;
            }
            return false;
        }
    }
    return false;
}
