// Triangle Geaometrical Primitive class
// Written by Sergey Kosov in 2005 for Rendering Competition

// Work with Kristian Sterjo
#pragma once

#include "Prim.h"

/**
 * @brief Triangle Geaometrical Primitive class
 */
class CPrimTriangle : public CPrim
{
public:
	/**
	 * @brief Constructor
	 * @param a Position of the first vertex
	 * @param b Position of the second vertex
	 * @param c Position of the third vertex
	 */

	// Adding a parameter for the color so the functionCALL is valid
	CPrimTriangle(Vec3f m_color, Vec3f a, Vec3f b, Vec3f c)
		: CPrim(m_color)
		, m_a(a)
		, m_b(b)
		, m_c(c)
  	{}
	virtual ~CPrimTriangle(void) = default;
	
	virtual bool Intersect(Ray& ray) override
	{
		// --- PUT YOUR CODE HERE ---
		Vec3f edge_AB = m_b - m_a; // (m_b - ray.org).cross(m_a - ray.org);
		Vec3f edge_BC = m_c - m_a; // (m_c - ray.org).cross(m_b - ray.org);
		Vec3f edge_CA = (m_a - ray.org).cross(m_c - ray.org);

		float t;
		float edge_sum = edge_AB.dot(ray.dir) + edge_BC.dot(ray.dir) + edge_CA.dot(ray.dir);
		float l1  = edge_AB.dot(ray.dir) / edge_sum;
		float l2  = edge_BC.dot(ray.dir) / edge_sum;
		float l3  = edge_CA.dot(ray.dir) / edge_sum;

		if(l1 < 0 || l2 < 0 || l3 < 0){
			//All the cases when the ray fails to interept the primitive
			return false;
		}

		Vec3f N = (m_b - m_a).cross(m_c - m_a);

		if(N.dot(ray.dir) == 0){
			return false;
		} else {
			t = (- N.dot(ray.org - m_a)) / (N.dot(ray.dir));
		} 

		if(t < Epsilon || t > ray.t){
			return false;
		}
		ray.t = t;

		return true;
	}

private:
	Vec3f m_a;	///< Position of the first vertex
	Vec3f m_b;	///< Position of the second vertex
	Vec3f m_c;	///< Position of the third vertex
};
