#pragma once

#include "ICamera.h"
#include "ray.h"

class CCameraOrthographic : public ICamera {
public:
    CCameraOrthographic(const Size &resolution, const Vec3f &dir, const Vec3f &up, float size);

    ~CCameraOrthographic() override;

    void InitRay(Ray &ray, int x, int y) override;

private:
    Vec3f m_direction;
    Vec3f m_up;
    float m_size;

    Vec3f m_xAxis;
    Vec3f m_yAxis;
    Vec3f m_zAxis;
};
