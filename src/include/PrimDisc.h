#pragma once

#include "IPrim.h"
#include "ray.h"

class CPrimDisc: public IPrim {
public:
    /**
     * @brief Constructor
     * @param origin Point on the plane
     * @param normal Normal to the plane
     */
    CPrimDisc();
    /**
     * @brief Constructor
     * @param origin Point on the plane
     * @param normal Normal to the plane
     */
    CPrimDisc(const Vec3f&, const Vec3f&, double);
    /**
     * @brief Constructor
     * @param origin Point on the plane
     * @param normal Normal to the plane
     */
    ~CPrimDisc() override;

    /**
     * @brief Constructor
     * @param origin Point on the plane
     * @param normal Normal to the plane
     */
    Vec3f getOrigin() const;

    /**
     * @brief Constructor
     * @param origin Point on the plane
     * @param normal Normal to the plane
     */
    Vec3f getNormal() const;

    /**
     * @brief Constructor
     * @param origin Point on the plane
     * @param normal Normal to the plane
     */
    double getRadius() const;

    bool intersect(Ray&) const override;

private:
    Vec3f m_origin;
    Vec3f m_normal;
    double m_radius;
};