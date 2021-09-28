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
		//defining the roots
		float t1,t2;

		Vec3f L = ray.org - m_center;
		float a = r1;
		float b = 2 * ray.dir.dot(L);
		float c = L.dot(L) - m_radius*m_radius;

		float d = b*b - 4*a*c;
		if(d < 0)
			return false; // negative discriminant not intersection found
		else if(dis == 0)
		{
			t1 = (-0.5) * B / A;
			t2 = (-0.5) * B / A;
		}else {	
			 t1 = (-0.5) * (B - sqrt(dis)) / A;
			 t2 = (-0.5) * (B + sqrt(dis)) / A;
		}
		// Make sure t2 is always the right value of t
		if(t1 > t2)
			std::swap(t1, t2);
		// Check the boundaries
		if( t1 < Epsilon || t1 > ray.t)
		{
			t1 = t2;
			if(t1 < Epsilon || t1 > ray.t) return false;
		}
		ray.t = t1;
		return true;
		 
	}
	
	
private:
	Vec3f m_origin;	///< Position of the center of the sphere
	float m_radius;	///< Radius of the sphere
};

