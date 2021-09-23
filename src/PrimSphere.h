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
		float a = ray.dir.dot(ray.dir);
		float b = 2 * ray.dir.dot(ray.org - m_origin);
		float c = (ray.org - m_origin).dot(ray.org - m_origin) - m_radius * m_radius;

		// Using discriminant
		float D = b * b - 4 * a * c;
		if(D < 0) {
		    return false;
		}
		float x1 = (-b + sqrt(D)) / (2 * a);
        float x2 = (-b - sqrt(D)) / (2 * a);

        if((x1 < Epsilon && x2 < Epsilon) || (x1 > ray.t && x2 > ray.t)) {
            return false;
        }

        if(x1 > x2) {
            ray.t = x2;
        }
        else {
            ray.t = x1;
        }

		return true;
	}
	
	
private:
	Vec3f m_origin;	///< Position of the center of the sphere
	float m_radius;	///< Radius of the sphere
};

