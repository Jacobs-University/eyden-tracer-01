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
		, m_normal(normal)
		, m_origin(origin)
	{
		normalize(m_normal);
	}
	virtual ~CPrimDisc(void) = default;

	virtual bool intersect(Ray& ray) const override
	{
		float t1;
		if(m.normal.dot(ray.dir) == 0) {
			return false;
		}
		else {
			t1 = ((m_origin - ray.origin).dot(m_normal))/(ray.dir.dot(m_normal))
		}

		if(t1<Epsilon || t1>ray.t)
		 	return false;
		
		ray.t = t1;
		return true;
	}
	
	
private:
	Vec3f m_normal;	///< Point on the plane
	Vec3f m_origin;	///< Normal to the plane
};
