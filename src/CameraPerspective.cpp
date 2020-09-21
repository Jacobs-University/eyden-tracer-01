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
CCameraPerspective::CCameraPerspective(Size resolution, const Vec3f &pos, const Vec3f &dir, const Vec3f &up,
                                       float angle)
        : ICamera(resolution), m_pos(pos), m_dir(dir), m_up(up) {
    // --- PUT YOUR CODE HERE ---
}

CCameraPerspective::~CCameraPerspective() = default;

void CCameraPerspective::InitRay(Ray &ray, int x, int y) {
    // --- PUT YOUR CODE HERE ---
}
