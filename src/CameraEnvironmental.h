#pragma once

#include "ICamera.h"
#include "ray.h"

// --- IMPLENET class CCameraEnvironmental ---
class CCameraEnvironmental : public ICamera
{
public:
	CCameraEnvironmental(Size resolution, const Vec3f& pos, const Vec3f& up)
		: ICamera(resolution)
		, m_pos(pos)
		, m_up(up)
	{}
	virtual ~CCameraEnvironmental(void) = default;

	virtual void InitRay(Ray& ray, int x, int y) override
	{
		//convert raster to angles
		Size res = getResolution();
		float phi = 2 * Pi * static_cast<float>(x) / res.width;
		float theta = Pi * static_cast<float>(y) / res.height;
		
		//define ray
		ray.dir = Vec3f(std::sin(theta) * std::cos(phi), std::cos(theta),
				std::sin(theta) * std::sin(phi));
		ray.org = m_pos;
		ray.t = std::numeric_limits<float>::infinity();
	}


private:
	// input values
	Vec3f m_pos;			///< Camera origin (center of projection)
	Vec3f m_up;				///< Camera up-vector
};
