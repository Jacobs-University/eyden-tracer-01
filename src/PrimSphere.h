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
		// --- PUT YOUR CODE HERE ---
		double SquareRadius = static_cast<double>(m_radius) * static_cast<double>(m_radius);
		auto BigL = m_origin - ray.org;
		double Tb = BigL.dot(ray.dir);
		auto h2 = pow(BigL.dot(BigL), 2) - pow(Tb, 2);
		//solve for t1 and t2
		const double a = 1;
		const double b = (-2 * static_cast<double>(ray.dir.dot(BigL)));
		const double c = static_cast<double>(BigL.dot(BigL)) - SquareRadius;
		double inroot = b * b - 4 * a * c;
		if (inroot < 0) return false;

		auto t1 = (-b + sqrt(inroot)) / (2 * a);
		auto t2 = (-b - sqrt(inroot)) / (2 * a);

		if (t1 < Epsilon && t2 < Epsilon) return false;
		//check if outof range
		if (t1 > ray.t && t2 > ray.t) return false;
		ray.t = t1 < t2 ? t1 : t2;

		return true;
	
	}
	
	
private:
	Vec3f m_origin;	///< Position of the center of the sphere
	float m_radius;	///< Radius of the sphere
};

