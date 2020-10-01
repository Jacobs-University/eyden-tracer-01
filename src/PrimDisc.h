#pragma once

#include "IPrim.h"
#include "ray.h"
#include <cmath>

// --- IMPLEMENT class CPrimDisc ---
// --- PUT YOUR CODE HERE ---
#include "PrimPlane.h"
class CPrimDisc : public IPrim
{
public:
	/**
	 * @brief Constructor
	 * @param origin Point on the plane
	 * @param normal Normal to the plane
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
		float distance;
		auto pa = norm(m_normal - m_origin);
		distance = (m_origin - ray.org).dot(m_normal) / ray.dir.dot(m_normal);
		if (distance<Epsilon || isinf(distance) || distance>ray.t|| pa>m_radius)
		{
			return false;
		}
		ray.t = distance;
		return true;
	}


private:
	Vec3f m_normal;	///< Point on the disc
	Vec3f m_origin;	///< Normal to the disc
	Vec3f m_radius;	///< radius of the disk
};
