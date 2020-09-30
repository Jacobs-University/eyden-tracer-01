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
	CPrimSphere(Vec3f &origin, float radius)
		: IPrim()
		, m_origin(origin)
		, m_radius(radius)
	{}
	virtual ~CPrimSphere(void) = default;

	virtual bool intersect(Ray &ray) const override
	{
		// --- PUT YOUR CODE HERE ---

		Vec3f vector = ray.org - m_radius;
		
		float a = ray.dir.dot(ray.dir);
		float b = 2 * ray.dir.dot(vector);
		float c = vector.dot(vector) - m_radius * m_radius;
		float d = b * b - 4 * a * c;

		if(d < 0) {
			return false;
		}

		float t = (-b - sqrt(d)) / a;

		if(t <= Epsilon) {
			t = (-b + sqrt(d)) / a;
			return true;
		}

		if(t < Epsilon || t > ray.t) {
			return false;
		}

		ray.t = t;
		return true;	
	}
	
	
private:
	Vec3f m_origin;	///< Position of the center of the sphere
	float m_radius;	///< Radius of the sphere
};

