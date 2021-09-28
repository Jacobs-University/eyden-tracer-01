// Perspective Camera class
// Written by Sergey Kosov in 2005 for Rendering Competition
#pragma once

#include "ICamera.h"
#include "ray.h"

// ================================ Perspective Camera Class ================================
/**
 * @brief Perspective Camera class
 * @ingroup moduleCamera
 * @author Sergey G. Kosov, sergey.kosov@project-10.de
 */
class CCameraPerspective : public ICamera
{
public:
	/**
	 * @brief Constructor
	 * @param resolution The image resolution in pixels
	 * @param pos Camera origin (center of projection)
	 * @param dir Normalized camera viewing direction
	 * @param up Normalized camera up-vector
	 * @param angle (Vertical) full opening angle of the viewing frustum in degrees
	 */
	CCameraPerspective(Size resolution, const Vec3f& pos, const Vec3f& dir, const Vec3f& up, float angle)
		: ICamera(resolution)
		, m_pos(pos)
		, m_dir(dir)
		, m_up(up)
	{
		m_dir = normalize(dir);	

		m_aspect =  (1.0) * resolution.width / resolution.height;
		m_focus = cotan(angle * M_PI / 360);

		m_yAxis = (-1) * m_up;
		m_xAxis = m_dir.cross(m_up);
	}
	virtual ~CCameraPerspective(void) = default;

	virtual void InitRay(Ray& ray, int x, int y) override
	{
		float ndcx = (x + 0.5) / getResolution().width;  
		float ndcy = (y + 0.5) / getResolution().height;
		float sscx = (2 * ndcx - 1) * m_aspect;  
		float sscy = (2 * ndcy - 1);

		Vec3f f = m_dir * m_focus;
		ray.org = m_pos;
		ray.dir =  f + sscx * m_xAxis + sscy * m_yAxis;
		
		ray.t   = 340282e+38;

		return true;
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

