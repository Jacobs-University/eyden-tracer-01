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
		// --- PUT YOUR CODE HERE ---
		m_zAxis = m_dir;
		m_xAxis = normalize(m_zAxis.cross(m_up));
		m_yAxis = normalize(m_zAxis.cross(m_xAxis));
		m_focus = 1.0f / tanf(angle * Pif / 360);
	}
	virtual ~CCameraPerspective(void) = default;

	virtual void InitRay(Ray& ray, int x, int y) override {
		// --- PUT YOUR CODE HERE ---
		Size resolution = getResolution();

        // scrSpCoord - screen space coordinates
 		float scrSpCoord_x = (2 * static_cast<float>(x) / resolution.width) - 1;
        float scrSpCoord_y = (2 * static_cast<float>(y) / resolution.width) - 1;

        ray.org = m_pos;
        ray.dir = normalize(getAspectRatio() * scrSpCoord_x * m_xAxis + scrSpCoord_y * m_yAxis + m_focus * m_zAxis);
        ray.t = std :: numeric_limits<float> :: infinity();
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

