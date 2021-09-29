// Sphere Geaometrical Primitive class
// Written by Sergey Kosov in 2005 for Rendering Competition
#pragma once

#include "IPrim.h"

/**
 * @brief Sphere Geaometrical Primitive class
 */
class CPrimSphere : public CPrim
{
public:
	/**
	 * @brief Constructor
	 * @param center Position of the center of the sphere
	 * @param radius Radius of the sphere
	 * @param color Color of the primitive
	 */
	CPrimSphere(Vec3f color, Vec3f center, float radius)
		: CPrim(color)
		, m_center(center)
		, m_radius(radius)
	{}
	virtual ~CPrimSphere(void) = default;

	virtual bool Intersect(Ray &ray) override
	{
		float t1, t2;

		Vec3f diff = ray.org - m_center;
		float A = ray.dir.dot(ray.dir);
		float B = 2 * ray.dir.dot(diff);
		float C = diff.dot(diff) - m_radius*m_radius;

		float dis = B*B - 4*A*C;
		if(dis < 0) {
			return false;
		}
		else if(dis == 0) {
			t1 = (-0.5) * B / A;
			t2 = (-0.5) * B / A;
		}
		else {	
			 t1 = (-0.5) * (B - sqrt(dis)) / A;
			 t2 = (-0.5) * (B + sqrt(dis)) / A;
		}
		if(t1 > t2) {
			std::swap(t1, t2);
		}
		if( t1 < Epsilon || t1 > ray.t)
		{
			t1 = t2;
			if(t1 < Epsilon || t1 > ray.t) return false;
		}
		ray.t = t1;
		return true;
		
	}
		
private:
	Vec3f m_center;	///< Position of the center of the sphere
	float m_radius;	///< Radius of the sphere
};

