#include "CameraPerspective.h"

// ================================ Perspective Camera Class ================================
/**
 * @brief Constructor
 * @param resolution The image resolution in pixels
 * @param pos Camera origin (center of projection)
 * @param dir Normalized camera viewing direction
 * @param up Normalized camera up-vector
 * @param angle (Vertical) full opening angle of the viewing frustum in degrees
 */
CCameraPerspective::CCameraPerspective(const Size& resolution, const Vec3f &pos, const Vec3f &dir, const Vec3f &up,
                                       float angle)
        : ICamera(resolution), m_pos(pos), m_dir(dir), m_up(up) {
    // We need to initialize the x, y and z axis.
    m_zAxis = normalize(m_dir);
    m_xAxis = normalize(m_dir.cross(m_up));
    m_yAxis = normalize(m_dir.cross(m_up).cross(m_dir));
}

CCameraPerspective::~CCameraPerspective() = default;

void CCameraPerspective::InitRay(Ray &ray, int x, int y) {
    auto res = this->getResolution();

    float sscx = 2 * (static_cast<float>(x) / res.width) - 1;
    float sscy = 2 * (static_cast<float>(y) / res.height) - 1;

    ray.org = m_pos;
    ray.dir = normalize(getAspectRatio() * sscx * m_xAxis + sscy * m_yAxis + m_focus * m_zAxis);
    ray.t = std::numeric_limits<float>::max();
}
