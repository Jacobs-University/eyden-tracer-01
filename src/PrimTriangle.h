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
        // Calculate vectors of edges
		Vec3f edge_1 = m_b - m_a;
		Vec3f edge_2 = m_c - m_a;

        Vec3f P = ray.dir.cross(edge_2);
        float determinant = P.dot(edge_1);

        if (abs(determinant) < Epsilon)
            return false;

        float inv_determinant = 1.0f / determinant;

        // Calculate vector from triangle point to ray origin
        Vec3f T = ray.org - m_a;
        float u = inv_determinant * P.dot(T);

        // Check if coordinate goes out of triangle bounds
        if (u < 0.0f || u > 1.0f)
            return false;
        
        Vec3f Q = T.cross(edge_1);
        float v = inv_determinant * Q.dot(ray.dir);

        // Check if coordinate goes out of triangle bounds
        if (v < 0.0f || v + u > 1.0f)
            return false;

        float t = inv_determinant * Q.dot(edge_2);

        if (t <= Epsilon || t >= ray.t)
            return false;
        
        ray.t = t;

        return true;
	}

	
private:
	Vec3f m_a;		///< Position of the first vertex
	Vec3f m_b;		///< Position of the second vertex
	Vec3f m_c;		///< Position of the third vertex
};
