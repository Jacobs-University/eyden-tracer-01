// Triangle Geaometrical Primitive class
// Written by Sergey Kosov in 2005 for Rendering Competition
#pragma once

#include "IPrim.h"
#include "ray.h"

// ================================ Triangle Primitive Class ================================
/**
 * @brief Triangle Geometrical Primitive class
 * @ingroup modulePrimitive
 * @author Sergey G. Kosov, sergey.kosov@project-10.de
 */
class CPrimTriangle : public IPrim
{
public:
	/**
	 * @brief Constructor
	 * @param a Position of the first vertex
	 * @param b Position of the second vertex
	 * @param c Position of the third vertex
	 */
	CPrimTriangle(const Vec3f& a, const Vec3f& b, const Vec3f& c)
		: IPrim()
		, m_a(a)
		, m_b(b)
		, m_c(c)
  	{}
	virtual ~CPrimTriangle(void) = default;
	
	virtual bool intersect(Ray& ray) const override
	{
		// Calculate normal of the triangle plane
		Vec3f normal = (m_b-m_a).cross(m_c-m_a);
		// Check if the ray is parallel to the plane
		if(normal.dot(ray.dir) == 0)
			return false;
		
		Vec3f nab = (m_b-ray.org).cross(m_a-ray.org);
		Vec3f nbc = (m_c-ray.org).cross(m_b-ray.org);
		Vec3f nca = (m_a-ray.org).cross(m_c-ray.org);

		float lambda_star1  = nab.dot(ray.dir);
		float lambda_star2  = nbc.dot(ray.dir);
		float lambda_star3  = nca.dot(ray.dir);
		float lambda_star_sum = (nca + nab + nbc).dot(ray.dir);

		float lambda1  = nab.dot(ray.dir) /lambda_star_sum;
		float lambda2  = nbc.dot(ray.dir) /lambda_star_sum;
		float lambda3  = nca.dot(ray.dir) /lambda_star_sum;

		if(lambda1 < 0)
			return false;
		if(lambda2 < 0)
			return false;
		if(lambda3 < 0)
			return false;

		float new_t = ((-1) * normal.dot(ray.org - m_a)) / normal.dot(ray.dir);
		if(new_t < Epsilon || new_t > ray.t)
			return false;

		ray.t = new_t;
		return true;
	}
	}

	
private:
	Vec3f m_a;		///< Position of the first vertex
	Vec3f m_b;		///< Position of the second vertex
	Vec3f m_c;		///< Position of the third vertex
};
