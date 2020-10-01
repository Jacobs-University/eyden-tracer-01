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
		, m_angle(angle)
	{
		// --- PUT YOUR CODE HERE ---
		m_aspect = (float) resolution.width / (float) resolution.height;
		m_focus = 1 / tan((m_angle * Pif) / 180);
		m_yAxis = normalize(m_up * (-1));
		m_xAxis = normalize(dir.cross(m_up));
		m_zAxis = normalize(m_dir);
	}

	virtual ~CCameraPerspective(void) = default;

	virtual bool InitRay(Ray& ray, int x, int y) override
	{
		// --- PUT YOUR CODE HERE ---
		float width = getResolution().width;
		float height = getResolution().height;

		float ndcx = (x + 0.5) / width; // Device coordinates
		float ndcy = (y + 0.5) / height;

		float sscx = (2 * ndcx - 1) * m_aspect; // Screen space coordinates
		float sscy = 2 * ndcy - 1;

		ray.org = m_pos;
		ray.dir = normalize(sscx * m_xAxis + sscy * m_yAxis + m_focus * m_dir);
		ray.t = std::numeric_limits<float>::max();

		return true;
	}


private:
	// input values
	Vec3f m_pos;			///< Camera origin (center of projection)
	Vec3f m_dir;			///< Camera viewing direction
	Vec3f m_up;				///< Camera up-vector
	float m_angle;			///< The focal length

	// preprocessed values
	float m_focus;
	float m_aspect;
	Vec3f m_xAxis;			///< Camera x-axis in WCS
	Vec3f m_yAxis;			///< Camera y-axis in WCS
	Vec3f m_zAxis;			///< Camera z-axis in WCS
};

