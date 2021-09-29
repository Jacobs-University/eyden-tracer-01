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

        // discriminant
        float D = b * b - 4 * a * c;
        if (D < 0) {
            return false;
        }

        // roots of the equation
        float t1;
        float t2;

        t1 = ((-b) + sqrt(D)) / 2 * a;
        t2 = ((-b) - sqrt(D)) / 2 * a;

        if ((t1 < Epsilon && t2 < Epsilon) || (t1 > ray.t && t2 > ray.t)) {
            return false;
        }

        if (t1 < t2) {
            ray.t = t1;
        }
        else {
            ray.t = t2;
        }

        return true;
	}
	
	
private:
	Vec3f m_origin;	///< Position of the center of the sphere
	float m_radius;	///< Radius of the sphere
};

