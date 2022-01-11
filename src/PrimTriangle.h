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
		/* The semantics of intersect should be as follows: 
		- Return true if and only if a valid intersection has been found in the interval (Epsilon, ray::t). Epsilon is defined in types.h. 
		- If a valid intersection has been found with the primitive, set ray::t to the distance to this intersection point (if current t < ray.t). 
		Find the closest intersection of the ray with the scene by just testing all in main.cpp defined primitives (s1, s2, s3, and p1) sequentially.
		*/
		// --- PUT YOUR CODE HERE ---
		
		auto e1 = m_b - m_a;
		auto e2 = m_c - m_a;

		auto BigT = ray.org - m_a;

		auto Q = BigT.cross(e1);
		auto P = ray.dir.cross(e2);

		//determinant
		//const Vec3f P = ray.dir.cross(e2);
		const float Det = e1.dot(P);
		auto InverseDet = 1 / Det;

		

		//Moller-Trumbore
		float u = BigT.dot(P);
		u *= InverseDet;
		float v = ray.dir.dot(Q);
		v *= InverseDet;

		if (u < 0.f || u > 1.f || v < 0.f || v + u > 1.f) {
			return false;
		}
		
		//if not false
		//calculate distance
		auto SmallT = (e2.dot(Q)) * InverseDet;
		if (ray.t <= SmallT || SmallT < Epsilon) {
			return false;
		}
		else {
			ray.t = SmallT;
			return true;
		}

		return false;
		
	}

	
private:
	Vec3f m_a;		///< Position of the first vertex
	Vec3f m_b;		///< Position of the second vertex
	Vec3f m_c;		///< Position of the third vertex
};
