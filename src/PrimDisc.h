#pragma once

#include "IPrim.h"
#include "ray.h"

// --- IMPLENET class CPrimDisc ---
// --- PUT YOUR CODE HERE ---

CPrimDisc::CPrimDisc() : IPrim() {
    m_radius = 1;
    m_origin = Vec3f(0, 0, 0);
    m_normal = Vec3f(0, 1, 0);
}

CPrimDisc::~CPrimDisc() = default;

Vec3f CPrimDisc::getNormal() const{
    return m_normal;
}

Vec3f CPrimDisc::getOrigin() const {
    return m_origin;
}

Vec3f CPrimDisc::getRadius() const {
    return m_radius;
}

virtual bool CPrimDisc::intersect(Ray &ray) const {

}