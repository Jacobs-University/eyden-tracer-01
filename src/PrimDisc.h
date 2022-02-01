#pragma once

#include "IPrim.h"
#include "ray.h"

// --- IMPLENET class CPrimDisc ---
// --- PUT YOUR CODE HERE ---

class CPrimDisc : public IPrim
{
public:
    /**
     * @brief Constructor
     * @param origin Point on the plane
     * @param normal Normal to the plane
     * @param radius radius of the disk
     */
    CPrimDisc(const Vec3f& origin, const Vec3f& normal, float radius)
        : IPrim()
        , m_normal(normal)
        , m_origin(origin)
        , m_radius(radius)
    {
        normalize(m_normal);
    }
    virtual ~CPrimDisc(void) = default;

    virtual bool intersect(Ray& ray) const override
    {
        // --- PUT YOUR CODE HERE ---

        float dist = (this -> m_origin - ray.org).dot(this -> m_normal) / ray.dir.dot(this -> m_normal);
                if (dist < Epsilon || isinf(dist) || ray.t < dist) {
                    return false;
                }
                Vec3f vec_from_org = (ray.org + dist * ray.dir) - m_origin;

                float dist_from_org = (sqrt(vec_from_org.dot(vec_from_org)));

                if (dist_from_org > m_radius) {
                    return false;
                }

                ray.t = dist;
                return true;
            }


private:
    Vec3f m_normal;    ///< Point on the plane
    Vec3f m_origin;    ///< Normal to the plane
    float m_radius;
};
