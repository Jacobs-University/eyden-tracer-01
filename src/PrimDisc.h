#pragma once

#include <iostream>
#include <cmath>
#include "IPrim.h"
#include "ray.h"
#include "PrimPlane.h"

// --- IMPLENET class CPrimDisc ---
// --- PUT YOUR CODE HERE ---

class CPrimDisc : public IPrim
{
public:
    /**
     * @brief Constructor
     * @param origin Point on the plane
     * @param normal Normal to the plane
     */
    CPrimDisc(Vec3f color, Vec3f origin, Vec3f normal, Vec3f radius)
        :IPrim(color)
        , m_normal(normal)
        , m_origin(origin)
        , m_radius(radius)
    {
        normalize(m_normal);
    }
    
    virtual ~CPrimDisc(void) = default;

    virtual bool intersect(Ray& ray) const override
    {
        // --- PUT YOUR CODE HERE ---
        float numerator = m_normal.dot(m_origin - ray.org);
        float denominator = m_normal.dot(ray.dir);
        float t;

        if (denominator == 0){
            return 0;
        }
        else{
            t = numerator / denominator;
        }
        
        

        if (t < Epsilon || t > ray.t){
            return false;
        }
        
        
      //  if (abs(m_normal - m_origin) > m_radius) {
      //     return false;
      // }
        
        ray.t = t;
        
        return true;
        
    }
    
    
  
    
    
private:

    Vec3f m_normal;    ///< Point on the plane
    Vec3f m_origin;    ///< Normal to the plane
    Vec3f m_radius;    ///< Radius of the disc
};
