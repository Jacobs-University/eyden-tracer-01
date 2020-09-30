// Plane Geaometrical Primitive class
// Written by Sergey Kosov in 2005 for Rendering Competition
#pragma once

#include "IPrim.h"
#include "ray.h"

// ================================ Infinite Plane Primitive Class ================================
/**
	* @brief The Plane Geometrical Primitive class
	* @ingroup modulePrimitive
	* @author Sergey G. Kosov, sergey.kosov@project-10.de
	*/
class CPrimPlane : public IPrim
{
public:
	/**
	 * @brief Constructor
	 * @param origin Point on the plane
	 * @param normal Normal to the plane
	 */
	CPrimPlane(const Vec3f& origin, const Vec3f& normal)
		: IPrim()
		, m_normal(normal)
		, m_origin(origin)
	{
		normalize(m_normal);
	}
	virtual ~CPrimPlane(void) = default;

	virtual bool intersect(Ray& ray) const override
	{
		// --- PUT YOUR CODE HERE ---
		float dim1 = - m_normal.dot(ray.org - m_origin);
		float dim2 = m_normal.dot(ray.dir);
		float t;

		if(dim2 == 0) {
			return false;
		} else {		
			t = dim1 / dim2; 
		}

		if(t < Epsilon || t > ray.t) {
			return false;
		}

		ray.t = t;
		return true;	
	}
	
	
private:
	Vec3f m_normal;	///< Point on the plane
	Vec3f m_origin;	///< Normal to the plane
};
