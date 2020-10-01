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
	CPrimSphere(const Vec3f &origin, float radius) // center = origin
		: IPrim()
		, m_origin(origin)
		, m_radius(radius)
	{}
	virtual ~CPrimSphere(void) = default;

	virtual bool intersect(Ray &ray) const override
	{
		// --- PUT YOUR CODE HERE ---
		float a = ray.dir.dot(ray.dir);
		float b = ray.dir.dot(ray.org - m_origin);
		float c = (ray.org - m_origin).dot(ray.org - m_origin) - (m_radius * m_radius);
		float discriminant = b * b - 4 * a * c;

		if(discriminant < 0) return false;

		float root_1 = ((-b) + sqrt(discriminant)) / 2 * a;
		float root_2 = ((-b) - sqrt(discriminant)) / 2 * a; 

		if((root_1 < Epsilon && root_2  < Epsilon) || (root_1 > ray.t && root_2 > ray.t)) return false;
		if(root_1 < root_2) ray.t = root_1;
		else ray.t = root_2;

		return true;
	}
	
	
private:
	Vec3f m_origin;	///< Position of the center of the sphere
	float m_radius;	///< Radius of the sphere
};

