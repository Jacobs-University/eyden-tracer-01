#include "CameraOrthographic.h"


CameraOrthographic::~CameraOrthographic() {

}

CameraOrthographic::CameraOrthographic(const Size &resolution, const Vec3f &pos, const Vec3f &dir, const Vec3f &up,
                                       float angle) : ICamera(resolution){
    m_xAxis = normalize(m_zAxis.cross(m_up));
    m_yAxis = normalize(m_zAxis.cross(m_xAxis));
    m_focus = 1.0f / tanf(angle * Pif / 360);
}

void CameraOrthographic::InitRay(Ray &ray, int x, int y) {
    Size resolution = getResolution();

    // Screen-space coordinates in [-1, 1]
    float sscx = (2 * static_cast<float>(x) / resolution.width) - 1;
    float sscy = (2 * static_cast<float>(y) / resolution.height) - 1;

    ray.org = m_pos;
    ray.dir = normalize(getAspectRatio() * sscx * m_xAxis + sscy * m_yAxis + m_focus * m_zAxis);
    ray.t   = std::numeric_limits<float>::infinity();
}

Vec3f CameraOrthographic::getOrigin() {
    return cv::Vec3f();
}
