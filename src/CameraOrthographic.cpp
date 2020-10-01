#include "CameraOrthographic.h"


CCameraOrthographic::~CCameraOrthographic() = default;

void CCameraOrthographic::InitRay(Ray &ray, int x, int y) {
    Size resolution = Size(getResolution().width / m_size, getResolution().height / m_size);

    /*
     * explaining what I'm attempting here:
     * The orthographic projection is a rather simple projection which maintains the
     * parallel lines that come with it. The camera does not technically have a ray origin but
     * the origin of each ray start from the given x and y coordinates in the init ray function.
     * However, we need to convert this to the camera coordinates system then use the direction of the
     * camera in order to shoot the ray towards the desired pixel. We then need to implement scaling so that
     * we're able to fit all of the elements of the camera space to our rather "small" screen space. We
     * can do this by somewhat scaling the screen in order to be able to map more in a small screen.
     *
     * However, currently something in the code is failing to convert this logic currently and I'm unsure
     * where this information is not being translated correctly.
     * */
    float ndcx = (static_cast<float>(x) / resolution.width);
    float ndcy = (static_cast<float>(y) / resolution.height);
// Screen-space coordinates in [-size, size]
    float sscx = ((2.0f * ndcx) - 1.0f) * m_size;
    float sscy = ((2.0f * ndcy) - 1.0f) * m_size;

    ray.org = Vec3f(x, y, 0);
    ray.dir = m_xAxis*sscx+ m_yAxis*sscy + m_zAxis;
    ray.t   = std::numeric_limits<float>::infinity();
}

CCameraOrthographic::CCameraOrthographic(const Size &resolution, const Vec3f &dir, const Vec3f &up, float size) : ICamera(resolution){
    m_direction = dir;
    m_up = up;
    m_zAxis = m_direction;
    m_xAxis = normalize(m_zAxis.cross(m_up));
    m_yAxis = normalize(m_zAxis.cross(m_xAxis));
    m_size = size;
}
