#pragma once

#include "IPrim.h"
#include "ray.h"

// ================================ Disc Primitive Class ================================
/**
    * @brief Disc Primitive class
    * @ingroup modulePrimitive
    */
class CPrimDisc : public IPrim
{
public:
    /**
     * @brief Constructor
     * @param origin Point on the disc
     * @param normal Normal to the disc
     * @param radius Radius of the disc
     */
    CPrimDisc(const Vec3f& origin, const Vec3f& normal, const float radius)
        : IPrim()
        , m_origin(origin)
        , m_normal(normal)
        , m_radius(radius)
    {
        normalize(m_normal);
    }
    virtual ~CPrimDisc(void) = default;

    virtual bool intersect(Ray& ray) const override
    {
        // Calculate vector from ray origin to origin of disc
        Vec3f L = m_origin - ray.org;

        // Calculate projection
        float proj = L.dot(m_normal);

        // Calculate distance of intersection from ray origin
        float t = proj / ray.dir.dot(m_normal);

        if (t <= Epsilon || t >= ray.t || isinf(t))
            return false;

        // Calculate vector from intersection from center of disc
        Vec3f intersect_vector = ray.org + t * ray.dir - m_origin;

        // Check if intersection point is outside of the disc
        if (sqrt(intersect_vector.dot(intersect_vector)) - m_radius > 0)
            return false;

        ray.t = t;

        return true;
    }


private:
    Vec3f m_normal;	///< Point on the disc
    Vec3f m_origin;	///< Normal to the disc
    float m_radius; ///< Radius of the disc
};
