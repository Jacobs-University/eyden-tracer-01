// Perspective Camera class
// Written by Sergey Kosov in 2005 for Rendering Competition

// Work with Kristian Sterjo

#pragma once

#include "ICamera.h"

/**
 * @brief Perspective Camera class
 */
class CCameraPerspective : public ICamera
{
public:
	/**
	 * @brief Constructor
	 * @param pos Camera origin (center of projection)
	 * @param dir Camera viewing direction
	 * @param up Up-vector
	 * @param angle (Vertical) full opening angle of the viewing frustum (in degrees)
	 * @param resolution The image resolution
	 */
	CCameraPerspective(Vec3f pos, Vec3f dir, Vec3f up, float angle, Size resolution)
		: ICamera(resolution)
		, m_pos(pos)
		, m_dir(dir)
		, m_up(up)
	{
		// --- PUT YOUR CODE HERE ---

		m_zAxis = dir;
		m_xAxis = m_zAxis.cross(m_up);
		//from the right hand rule the x axis is the
		//cross product of the up vector and zaxis
		m_yAxis = m_zAxis.cross(m_xAxis);

		//getting the norm values
		m_xAxis = normalize(m_xAxis);
		m_yAxis = normalize(m_zAxis);
		m_zAxis = normalize(m_zAxis);

		m_aspect = (float) resolution.width / resolution.height;
		m_focus = 1.0 / tan(angle/2 * Pif / 180);

	}
	virtual ~CCameraPerspective(void) = default;

	virtual bool InitRay(float x, float y, Ray& ray) override
	{
		// --- PUT YOUR CODE HERE ---
		float sscx = (2 * ( (x + 0.5f)/ getResolution().width))-1 ;
		float sscy = (2 * ( (y + 0.5f)/ getResolution().height))-1 ;

		ray.org = m_pos;
		ray.dir = normalize (m_aspect * sscx * m_xAxis + sscy * m_yAxis + m_focus*m_dir);
		ray.t = std::numeric_limits<float>::infinity();

		return true;
	}


private:
	// input values
	Vec3f m_pos;
	Vec3f m_dir;
	Vec3f m_up;

	// preprocessed values
	float m_focus;
	Vec3f m_xAxis;
	Vec3f m_yAxis;
	Vec3f m_zAxis;
	float m_aspect;
};

