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
	 */
	CPrimDisc(const Vec3f& origin, const Vec3f& normal)
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
		//discance between ray origin and m_origin
        Vec3f L = m_origin - ray.org;

        float p = L.dot(m_normal);

        float t = p / ray.dir.dot(m_normal);

        if (t <= Epsilon || t >= ray.t || isinf(t))
            return false;

        Vec3f intersect_vector = ray.org + t * ray.dir - m_origin;

        if (sqrt(intersect_vector.dot(intersect_vector)) - m_radius > 0)
            return false;

        ray.t = t;

        return true;
	}
	
	
private:
	Vec3f m_normal;	///< Point on the disc plane
	Vec3f m_origin;	///< Normal to the disc plane
	 float m_radius; ///< Radius of the disc
};
