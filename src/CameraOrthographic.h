#pragma once

#include "ICamera.h"
#include "ray.h"

// --- IMPLENET class CCameraOrthographic ---
// --- PUT YOUR CODE HERE ---

class CCameraOrthographic : public ICamera
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
	CCameraOrthographic(Size resolution, const Vec3f& pos, const Vec3f& dir, const Vec3f& up, float angle)
		: ICamera(resolution)
		, m_dir(dir)
		, m_up(up)
		, m_angle(angle)
	{
		// --- PUT YOUR CODE HERE ---
		//copied from lecture
		Vec3f	m_angle;	// Origin (center of projection)
		Vec3f	m_dir;	// Viewing direction
		Vec3f	m_up;	// Up-vector
		//Size resolution = getResolution();

		// Define Camera coordinate system
		Vec3f zAxis = m_dir;
		Vec3f xAxis = normalize(zAxis.cross(m_up));
		Vec3f yAxis = normalize(zAxis.cross(xAxis));

	}
	virtual ~CCameraOrthographic(void) = default;

	virtual void InitRay(Ray& ray, int x, int y) override
	{
		Size resolution = getResolution();

		// Normalized device coordinates in [0, 1]
		float ndcx = static_cast<float>(x) / resolution.width;
		float ndcy = static_cast<float>(y) / resolution.height;

		// Screen-space coordinates in [-1, 1]
		float sscx = 2 * ndcx - 1;
		float sscy = 2 * ndcy - 1;
	}


private:
	// input values
	Vec3f m_dir;			///< Camera viewing direction
	Vec3f m_up;				///< Camera up-vector
	float m_angle;

	// preprocessed values
	Vec3f m_xAxis;			///< Camera x-axis in WCS
	Vec3f m_yAxis;			///< Camera y-axis in WCS
	Vec3f m_zAxis;			///< Camera z-axis in WCS
};

