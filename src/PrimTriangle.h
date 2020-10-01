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
		// --- PUT YOUR CODE HERE ---
		//Möller-Trumbore algorithm from the slides
		Vec3f m_edge1 = m_b - m_a;
		Vec3f m_edge2 = m_c - m_a;
		const Vec3f pvec = ray.dir.cross(m_edge2);
		const float det = m_edge1.dot(pvec);
		if (fabs(det) < Epsilon) {
			return false;
		}

		const float inv_det = 1.0f / det;
		const Vec3f tvec = ray.org - m_a;
		float u = tvec.dot(pvec);
		u *= inv_det;
		if (u < 0.0f || u > 1.0f)
		{
			return false;
		}

		const Vec3f qvec = tvec.cross(m_edge1);
		float v = ray.dir.dot(qvec);
		v *= inv_det;
		if (v < 0.0f || v + u > 1.0f) 
		{
			return false;
		}

		float t = m_edge2.dot(qvec);
		t *= inv_det;
		if (ray.t <= t || t < Epsilon)
			return false;

		ray.t = t;
		return true;
	}

	
private:
	Vec3f m_a;		///< Position of the first vertex
	Vec3f m_b;		///< Position of the second vertex
	Vec3f m_c;		///< Position of the third vertex
	//Vec3f m_color;	///< Color of the triangle
};
