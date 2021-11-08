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
		Vec3f L = this -> m_origin - ray.org;

		float a = 1;
		float b = static_cast<float>(-2 * ray.dir.dot(L));
		float c = 	static_cast<float>(L.dot(L)) - static_cast<float>(this -> m_radius * this -> m_radius);

		float D = b * b - 4 * a * c;

		if (D < 0) {
			return false;
		} else {

			float t1 = (-b + sqrt(D)) / (2 * a);
			float t2 = (-b - sqrt(D)) / (2 * a);

			if (t1 < Epsilon || t1 > ray.t) {
				return false;
			} else {

				ray.t = t2 > Epsilon ? t2 : t1;
				return true;
			}
		}
	}
	
	
private:
	Vec3f m_origin;	///< Position of the center of the sphere
	float m_radius;	///< Radius of the sphere
};

