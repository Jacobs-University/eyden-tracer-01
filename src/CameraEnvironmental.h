#pragma once

#include "ICamera.h"
#include "ray.h"

// --- IMPLENET class CCameraEnvironmental ---
// --- PUT YOUR CODE HERE ---

class CCameraEnvironmental : public ICamera
{
public:
    /**
     * @brief Constructor
     * @param resolution The image resolution in pixels
     * @param pos Camera origin (center of projection)
     * @param dir Normalized camera viewing direction
     * @param up Normalized camera up-vector
     */
    CCameraEnvironmental(Size resolution, const Vec3f& pos, const Vec3f& dir, const Vec3f& up)
        : ICamera(resolution)
        , m_pos(pos)
        , m_dir(dir)
        , m_up(up)
    {
        m_zAxis = dir;
        m_xAxis = normalize(m_zAxis.cross(up));
        m_yAxis = normalize(m_zAxis.cross(m_xAxis));
    }
    virtual ~CCameraEnvironmental(void) = default;

    virtual void InitRay(Ray& ray, int x, int y) override
    {
        float phi = 2 * Pif * static_cast<float>(x) / getResolution().width;
        float theta = Pif * static_cast<float>(y) / getResolution().height;

        ray.org = m_pos;
        ray.dir = normalize(cosf(phi) * sinf(theta) * m_xAxis - cosf(theta) * m_yAxis + sinf(phi) * sinf(theta) * m_zAxis);
        ray.t = std::numeric_limits<float>::infinity();
    }


private:
    Vec3f m_pos;
    Vec3f m_dir;
    Vec3f m_up;

    Vec3f m_xAxis;
    Vec3f m_yAxis;
    Vec3f m_zAxis;
};