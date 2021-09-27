// Sphere Geaometrical Primitive class
// Written by Sergey Kosov in 2005 for Rendering Competition
#pragma once

#include "IPrim.h"
#include "ray.h"

// ================================ Sphere Primitive Class ================================
/**
 * @brief Sphere Geaometrical Primitive class
 * @ingroup modulePrimitive
 * @author Sergey G. Kosov, sergey.kosov@project-10.de
 */
class CPrimSphere : public IPrim
{
public:
    /**
     * @brief Constructor
         * @param origin Position of the center of the sphere
         * @param radius Radius of the sphere
     */
    CPrimSphere(Vec3f origin, float radius)
        : IPrim()
        , m_origin(origin)
        , m_radius(radius)
    {}
    virtual ~CPrimSphere(void) = default;

    virtual bool intersect(Ray &ray) const override
    {
        float t;
        float r_sq = pow(m_radius, 2);

        // Calculate vector from ray origin to center of sphere
        Vec3f L = m_origin - ray.org;

        // Calculate distance to intersection of ray with perpendicular radius
        float tb = ray.dir.dot(L);

        // Calculate the square of the length of the ray originating from
        // sphere origin perpendicular to the ray direction
        float h_sq = L.dot(L) - pow(tb, 2);


        if (h_sq > r_sq)
            // Ray does not intersect sphere
            return false;
        else if (abs(r_sq - h_sq) < Epsilon)
            // Ray is tangent to the surface of the sphere
            t = tb;
        else {
            double delta = sqrt(r_sq - h_sq);

            // Calculate the nearest intersection
            t = tb + (L.dot(L) < m_radius ? 1.0f : -1.0f) * delta;
        }

        if (t <= Epsilon || t >= ray.t)
            return false;

        ray.t = t;

        return true;
    }


private:
    Vec3f m_origin;	///< Position of the center of the sphere
    float m_radius;	///< Radius of the sphere
};

