#pragma once

#include "ICamera.h"
#include "ray.h"

#define _USE_MATH_DEFINES
#include <math.h>
// --- IMPLEMENT class CCameraEnvironmental ---
// --- PUT YOUR CODE HERE ---

class CCameraEnvironmental : public ICamera
{
public:
	CCameraEnvironmental(Size resolution, const Vec3f& pos, float angle)
		: ICamera(resolution)
		, m_pos(pos)
	{
	}
	virtual ~CCameraEnvironmental(void) = default;

	virtual void InitRay(Ray& ray, int x, int y) override
	{
		// --- PUT YOUR CODE HERE ---
		float dx = x;
		float dy = y;

		auto height = getResolution().height;
		auto width = getResolution().width;

		double theta = 2 * M_PI * dx / height;
		double phi = acos(1 - 2 * dy / width);
		double x1 = sin(phi) * cos(theta);
		double y1 = sin(phi) * sin(theta);
		double z = cos(phi);
		Vec3f spherePoint = Vec3f(x1, y1, z);

		ray.org = m_pos;
		ray.dir = normalize(spherePoint - m_pos);
		ray.t = std::numeric_limits<float>::infinity();

	}


private:
	// input values
	Vec3f m_pos;			///< Camera origin (center of projection)
};

