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
		m_dir(dir)

	{

	}

	virtual ~CCameraEnvironmental(void) = default;

	virtual void InitRay(Ray& ray, int x, int y) {

		Size res = getResolution();


		float theta = Pif * (y / res.height);
		float phi = Pif * 2 * (x / res.width);

		m_zAxis = m_dir;
		m_xAxis = normalize(m_zAxis.cross(m_up));
		m_yAxis = normalize(m_zAxis.cross(m_xAxis));

		ray.org = m_pos;
        ray.dir = normalize(cosf(phi) * sinf(theta) * m_xAxis + sinf(theta) * sinf(phi) * m_yAxis - cosf(theta) * m_zAxis);
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