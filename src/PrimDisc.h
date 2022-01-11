#pragma once

#include "IPrim.h"
#include "ray.h"
#include "PrimPlane.h"
// --- IMPLENET class CPrimDisc ---
// --- PUT YOUR CODE HERE ---


class CPrimDisc : public IPrim
{
public:
	
	CPrimDisc(const Vec3f& origin, const Vec3f& normal, const float radius)
		: IPrim()
		, m_origin(origin)
		, m_radius(radius)
		, m_normal(normal)
	{}
	virtual ~CPrimDisc(void) = default;

	virtual bool intersect(Ray& ray) const override
	{
		auto Distance = ((m_origin - ray.org).dot(m_normal)) / ray.dir.dot(m_normal);
		if (Distance > ray.t || isinf(Distance) || Distance < Epsilon) { return false; }
		const Vec3f Point = ray.org + ray.t * ray.dir;
		auto DistanceToOrigin = sqrt((Point - m_origin).dot(Point - m_origin));
		if (DistanceToOrigin > m_radius) return false;
		ray.t = Distance;
		return true;
	}


private:
	Vec3f m_normal;	///< Point on the plane
	Vec3f m_origin;	///< Normal to the plane
	float m_radius;	///< Radius of the disc
};