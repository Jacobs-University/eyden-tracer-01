#pragma once

#include "ICamera.h"
#include "ray.h"

// --- IMPLEMENT class CCameraEnvironmental ---
// --- PUT YOUR CODE HERE ---

class CCameraEnvironmental : public ICamera
{
public:
    CCameraEnvironmental(Size resolution, const Vec3f& pos, float angle)
    : ICamera(resolution)
    , m_pos(pos)
    {}

    virtual ~CCameraEnvironmental(void) = default;
    virtual void InitRay(Ray& ray, int x, int y) override {

        auto height = getResolution().height;
        auto width = getResolution().width;

        // finding the normalized
        double theta = 2 * Pif * x / width;
        double phi = Pif * y / height;

        double x1 = sin(phi) * cos(theta);
        double y1 = sin(phi) * sin(theta);
        double z = cos(phi);
        Vec3f spherePoint = Vec3f(x1, y1, z);

        ray.org = m_pos;
        ray.dir = normalize(spherePoint - m_pos);
        ray.t = std :: numeric_limits<float> :: infinity();
    }
private:
    // camera origin
    Vec3f m_pos;
};
