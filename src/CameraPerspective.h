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
        //New coordinate system for each object that meets with the ray(Camera coordinate system)
        m_zAxis = m_dir;    //Goes with the direction of the axis
        m_xAxis = m_zAxis.cross(m_up);    //zaxis  x m_up
        m_yAxis = m_zAxis.cross(m_xAxis);
        //1.0f / tanf(angle * Pif / 360)
        m_focus = 1.0f / tanf(angle * Pif / 360);
	}
	virtual ~CCameraPerspective(void) = default;

	virtual void InitRay(Ray& ray, int x, int y) override
	{
		// --- PUT YOUR CODE HERE ---

        Size resolution = getResolution();       //Resoltion is a private member of camera


        //New coordinate system for each object that meets with the ray(Camera coordinate system)
        Vec3f zaxis = m_dir;    //Goes with the direction of the axis
        Vec3f xaxis = zaxis.cross(m_up);    //zaxis  x m_up
        Vec3f yaxis = zaxis.cross(xaxis);

        //Raster to NDC (We create a coordinate system in the Object)
        float ndcx = static_cast<float>(x + 0.5f) / resolution.width;
        float ndcy = static_cast<float>(y + 0.5f) / resolution.width;

        //Screen coordinate (coordinate of the pixel on the object)
        float sscx = 2 * (x + 0.5f) / resolution.width - 1;
        float sscy = 2 * (y + 0.5f) / resolution.height - 1;

        // Let us generate the ray
//        ray.org = m_pos; //The origine of the ray is the origine of the camera
//        ray.t = std::numeric_limits<float>::infinity(); //We don't know when will the ray hit an object
//        Vec3f p = m_pos + zaxis*m_focus + xaxis*sscx + yaxis*sscy; // Position of the ray in the object
//        ray.dir = p - m_pos;      //Direction of the array is known by locating the ray in object and linking it with the camera position

        ray.org = m_pos;
        ray.dir = normalize(getAspectRatio() * sscx * m_xAxis + sscy * m_yAxis + m_focus * m_zAxis);
        ray.t = std::numeric_limits<double>::infinity();
        
	}


private:
	// input values
	Vec3f m_pos;			///< Camera origin (center of projection)
	Vec3f m_dir ;			///< Camera viewing direction
	Vec3f m_up;				///< Camera up-vector
	float m_focus;			///< The focal length

	// preprocessed values
	Vec3f m_xAxis;			///< Camera x-axis in WCS
	Vec3f m_yAxis;			///< Camera y-axis in WCS
	Vec3f m_zAxis;			///< Camera z-axis in WCS
};


