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
		const Vec3f e1 = m_b - m_a;
		const Vec3f e2 = m_c - m_a;

		const Vec3f P = ray.dir.cross(e2);

		const float deter = e1.dot(P);

		if (deter < Epsilon) {
			return false;
		} 

		const float inverse_deter = 1.0f / deter;

		const Vec3f T = ray.org - m_a;
		float u = inverse_deter * (T.dot(P));

		if (u > 1.0f || u < 0.0f) {
			return false;
		}


		const Vec3f Q = T.cross(e1);
		float v = inverse_deter * (Q.dot(ray.dir));
		if (v < 0.0f || v + u >= 1.0f) {
			return false;
		} 


		float t = inverse_deter * (e2.dot(Q));

		if (t >= ray.t || t < Epsilon) {
			return false;
		}

		ray.t = t;
		return true;
	}

	
private:
	Vec3f m_a;		///< Position of the first vertex
	Vec3f m_b;		///< Position of the second vertex
	Vec3f m_c;		///< Position of the third vertex
};
