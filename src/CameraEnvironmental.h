#pragma once

#include "ICamera.h"
#include "ray.h"

// --- IMPLENET class CCameraEnvironmental ---
// --- PUT YOUR CODE HERE ---


class CCameraEnvironmental: public ICamera {

public:

	CCameraEnvironmental(Size resolution, const Vec3f& pos, const Vec3f& dir, const Vec3f& up) :
		ICamera(resolution),
		m_pos(pos),
		m_dir(dir),
		m_up(up)

	{

	}

	virtual ~CCameraEnvironmental(void) = default;

	virtual void InitRay(Ray& ray, int x, int y) {

		Size res = getResolution();


		float theta = Pif * (static_cast<float>(y) / res.height);
		float phi = Pif * 2 * (static_cast<float>(x) / res.width);

		m_zAxis = m_dir;
		m_xAxis = normalize(m_zAxis.cross(m_up));
		m_yAxis = normalize(m_zAxis.cross(m_xAxis));

		ray.org = m_pos;
        ray.dir = normalize(cosf(phi) * sinf(theta) * m_xAxis + sinf(theta) * sinf(phi) * m_zAxis - cosf(theta) * m_yAxis);
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