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
		//define edges
		Vec3f edge1 = m_a - m_b;
		Vec3f edge2 = m_a - m_c;
		
		// calc helper vectors
		const Vec3f P = ray.dir.cross(edge2);
		const float det = edge1.dot(P);
		if (fabs(det) < Epsilon)
			return false;
		
		
		const float inv_det = 1.0f / det;
		const Vec3f T = ray.org - m_a;
		float u = T.dot(P);
		u *= inv_det;
		if (u < 0.0f || u > 1.0f)
			return false;
		
		const Vec3f Q = T.cross(edge2);
		float v = ray.dir.dot(Q);
		v *= inv_det;
		if (v < 0.0f || v + u > 1.0f)
			return false;
		
		// calc distance
		float t = edge2.dot(Q);
		t *= inv_det;
		if (ray.t <= t || t < Epsilon) {
			return false;
		} else {
			ray.t = t;
			return true;
		}
		
	}

	
private:
	Vec3f m_a;		///< Position of the first vertex
	Vec3f m_b;		///< Position of the second vertex
	Vec3f m_c;		///< Position of the third vertex
};
