// Sphere Geaometrical Primitive class
// Written by Sergey Kosov in 2005 for Rendering Competition
#pragma once

#include "IPrim.h"
#include "ray.h"

// ================================ Sphere Primitive Class ================================
/**
 * @brief Sphere Geaometrical Primitive class
 * @ingroup modulePrimitive
 * @author Sergey G. Kosov, sergey.kosov@project-10.de
 */
class CPrimSphere : public IPrim {
public:
    /**
     * @brief Constructor
         * @param origin Position of the center of the sphere
         * @param radius Radius of the sphere
     */
    CPrimSphere(const Vec3f &origin, float radius);

    ~CPrimSphere() override;

    bool intersect(Ray &ray) const override;

private:
    Vec3f m_origin;    ///< Position of the center of the sphere
    float m_radius;    ///< Radius of the sphere
};

