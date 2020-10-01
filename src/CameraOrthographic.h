#pragma once

#include "ICamera.h"
#include "ray.h"

// --- IMPLENET class CCameraOrthographic ---
// --- PUT YOUR CODE HERE ---
class  CameraOrthographic : ICamera 
{
public:

    CameraOrthographic(Size& resolution, const Vec3f& pos, const Vec3f& dir, const Vec3f& up, float angle)
    : ICamera(resolution) 
    , m_pos(pos)
    , m_dir(dir)
    , m_up(up)
    , m_angle(angle)
    {
        m_xAxis = normalize(m_zAxis.cross(m_up));
        m_yAxis = normalize(m_zAxis.cross(m_xAxis));
        m_focus = 1 / tan((m_angle * Pif) / 180);
    }

    virtual ~CameraOrthographic(void) = default;

    virtual bool InitRay(Ray &ray, int x, int y) override
    {
        float width = getResolution().width;
        float height = getResolution().height;

        float sscx = (2 * static_cast<float>(x) / width) - 1;
        float sscy = (2 * static_cast<float>(y) / height) - 1;

        ray.org = m_pos;
        ray.dir = normalize(getAspectRatio() * sscx * m_xAxis + sscy * m_yAxis + m_focus * m_zAxis);
        ray.t   = std::numeric_limits<float>::max();

        return true;
    }

    Vec3f getOrigin() {
        return cv::Vec3f();
    }

private:
    Vec3f m_pos;
    Vec3f m_dir;
    Vec3f m_up;
    float m_angle;

    Vec3f m_xAxis;
    Vec3f m_yAxis;
    Vec3f m_zAxis;
    float m_focus;
    float m_aspect;
};
