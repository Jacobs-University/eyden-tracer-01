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
		//calc quadratic coeficients
		Vec3f L = ray.org - m_origin;
		double a = 1;
		double b = 2 * static_cast<double>(ray.dir.dot(L));
		double c = static_cast<double>(L.dot(L)) - (static_cast<double>(m_radius)*static_cast<double>(m_radius));
		
		//use quadratic formula to find intersections
		double inRoot = b * b - 4 * a * c;
		if (inRoot < 0)
			return false;
		double root = sqrt(inRoot);
		double t0 = (-b - root) / (2 * a);
		double t1 = (-b + root) / (2 * a);
		
		if ((t0 > ray.t && t1 > ray.t) || (t0 < Epsilon && t1 < Epsilon)) {
			return false;
		} else {
			ray.t = t0 < t1 ? t0 : t1;
			return true;
		}
	}
	
	
private:
	Vec3f m_origin;	///< Position of the center of the sphere
	float m_radius;	///< Radius of the sphere
};

