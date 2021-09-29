#pragma once

#include "IPrim.h"
#include "ray.h"

// --- IMPLENET class CPrimDisc ---
class CPrimDisc : public CPrimPlane
{
public:
	/**
	 * @brief Constructor
	 * @param origin Point on the plane
	 * @param normal Normal to the plane
	 */
	CPrimDisc(const Vec3f& origin, const Vec3f& normal, const float radius)
		: CPrimPlane(origin, normal)
		, m_radius(radius)
	{}
	virtual ~CPrimDisc(void) = default;

	virtual bool intersect(Ray& ray) const override
	{
		float t = ray.t;
		if (!CPrimPlane::intersect(ray))
			return false;
		
		//find point of intersection
		Vec3f p = ray.org + ray.dir*ray.t;
		
		//check if plane intersection is within the radius
		Vec3f dist = p - m_origin;
		if (sqrt(static_cast<double>(dist.dot(dist))) <= m_radius) {
			return true;
		} else {
			ray.t = t; //correct false modification in CPrimPlane::intersect
			return false;
		}
	}
	
	
private:
	float m_radius;	///< Radius of the disc
};
