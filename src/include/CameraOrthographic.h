#pragma once

#include "ICamera.h"
#include "ray.h"

class CameraOrthographic : ICamera {
    ~CameraOrthographic();
    CameraOrthographic(const Size& resolution, const Vec3f &pos, const Vec3f &dir, const Vec3f &up, float angle);

    void InitRay(Ray &ray, int x, int y) override;

    Vec3f getOrigin();
private:
    Vec3f m_pos;
    Vec3f m_direction;
    Vec3f m_up;
    double m_size;

    Vec3f m_xAxis;
    Vec3f m_yAxis;
    Vec3f m_zAxis;
    double m_focus;
};
