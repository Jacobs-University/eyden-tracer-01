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
        double r2 = static_cast<double>(m_radius) * static_cast<double>(m_radius);
        
        
        Vec3f difference = ray.org - m_origin;
        double a = static_cast<double>(ray.dir.dot(ray.dir));    //Must be equal to 1 since we normalize the ray direction.
        double b = 2 * static_cast<double>(ray.dir.dot(difference));    //2*d*L
        double c = static_cast<double>(difference.dot(difference)) - m_radius * m_radius;   // L^2 - r^2

        double delta = b * b - 4 * a * c;       //calculation of delta

        if (delta < 0) return false;    //Ray doesn't intersect

        double t1 = (-b - sqrt(delta)) / 2 * a;
        double t2 = (-b + sqrt(delta)) / 2 * a;

        if (t1 > t2) std::swap(t1, t2);     //t1 is the furthuest point -> se swap them

        if(t1 < 0){ //Ray is shooted from the inside of the sphere
            t1 = t2; //We use only t2

            if (t2 < 0) return false; //The ray is shooted from the opposite direction of the sphere
        }

        ray.t = t1;     //Distance is the smallest existing distance
        return true;	}
	
	
private:
	Vec3f m_origin;	///< Position of the center of the sphere
	float m_radius;	///< Radius of the sphere
};

