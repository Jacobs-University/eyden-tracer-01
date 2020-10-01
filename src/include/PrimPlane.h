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
class CPrimPlane : public IPrim {
public:
    /**
     * @brief Constructor
     * @param origin Point on the plane
     * @param normal Normal to the plane
     */
    CPrimPlane(const Vec3f &origin, const Vec3f &normal);

    ~CPrimPlane() override;

    bool intersect(Ray &ray) const override;


private:
    Vec3f m_normal;    ///< Point on the plane
    Vec3f m_origin;    ///< Normal to the plane
};
