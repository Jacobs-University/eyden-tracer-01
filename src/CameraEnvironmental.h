#pragma once

#include "ICamera.h"
#include "ray.h"

// --- IMPLENET class CCameraEnvironmental ---
// --- PUT YOUR CODE HERE ---

class CCameraEnvironmental : public ICamera 
{
public:
	CCameraEnvironmental(Size resolution, const Vec3f& pos, const Vec3f& dir,
		const Vec3f& up, float angle)
		: ICamera(resolution)
		, m_pos(pos)
		, m_up(up)
	{
		//m_focus = pow(pos[0],2) - pow(pos[])
		////define orientation
		//m_zAxis = m_dir;
		//m_xAxis = normalize(m_zAxis.cross(up));
		//m_yAxis = normalize(m_zAxis.cross(m_xAxis));
	}
	virtual void InitRay(Ray& ray, int x, int y) override 
	{
		/*
		PBR book
		<<Compute environment camera ray direction>>=
		Float theta = Pi * sample.pFilm.y / film->fullResolution.y;
		Float phi = 2 * Pi * sample.pFilm.x / film->fullResolution.x;
		Vector3f dir(std::sin(theta) * std::cos(phi), std::cos(theta),
		std::sin(theta) * std::sin(phi));
		*/
		auto Resolution = getResolution();
		float theta = Pi * static_cast<float>(y) / Resolution.height;
		float phi = 2 * Pi * static_cast<float>(x) / Resolution.width;
		ray.dir = Vec3f(sinf(theta) * cosf(phi), 
			cosf(theta), 
			sinf(theta) * sinf(phi)
		);
		ray.org = m_pos;
		ray.t = float(INFINITY);
	}

private:
	// input values
	Vec3f m_pos;			///< Camera origin (center of projection)
	Vec3f m_dir;			///< Camera viewing direction
	Vec3f m_up;				///< Camera up-vector
	float m_focus;			///< The focal length

	// preprocessed values
	Vec3f m_xAxis;			///< Camera x-axis in WCS
	Vec3f m_yAxis;			///< Camera y-axis in WCS
	Vec3f m_zAxis;			///< Camera z-axis in WCS
};