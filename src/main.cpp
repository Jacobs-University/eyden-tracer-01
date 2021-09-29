#include "CameraPerspective.h"
#include "CameraEnvironmental.h"

#include "PrimDisc.h"
#include "PrimSphere.h"
#include "PrimPlane.h"
#include "PrimTriangle.h"

void updateIfDistanceChange(Ray&, float&, Vec3f&, Vec3f);

Mat RenderFrame(ICamera& camera)
{
	// scene objects
	
	// CPrimSphere s1(Vec3f(-2, 1.7f, 0), 2);
	CPrimSphere s2(Vec3f(1, -1, 1), 2.2f);
	CPrimSphere s3(Vec3f(3, 0.8f, -2), 2);
	CPrimPlane p1(Vec3f(0, -1, 0), Vec3f(0, 1, 0));
	// Add disc primitive here
	CPrimDisc d1(Vec3f(-2, 1.7f, 0), Vec3f(0, 1, 0), 1.0);
	
	CPrimTriangle t1(Vec3f(-2, 3.7f, 0), Vec3f(1, 2, 1), Vec3f(3, 2.8f, -2));
	CPrimTriangle t2(Vec3f(3, 2, 3), Vec3f(3, 2, -3), Vec3f(-3, 2, -3));
	
	Mat img(camera.getResolution(), CV_32FC3); 	// image array
	Ray ray;                            		// primary ray
	
	for(int y = 0; y< img.rows; y++)
		for (int x = 0; x < img.cols; x++) {
			
			// Initialize your ray here
			
			// --- PUT YOUR CODE HERE ---
			camera.InitRay(ray, y, x);
			
			Vec3f col = RGB(0, 0, 0); // background color
			
			/*
			 * Find closest intersection with scene
			 * objetcs and calculate color
			 */
			
			 // --- PUT YOUR CODE HERE ---

			float maxDistance = std::numeric_limits<float>::infinity();

			d1.intersect(ray);
			updateIfDistanceChange(ray, maxDistance, col, RGB(1, 0, 0));
				

			s2.intersect(ray);
			updateIfDistanceChange(ray, maxDistance, col, RGB(0, 1, 0));
			
				

			s3.intersect(ray);
			updateIfDistanceChange(ray, maxDistance, col, RGB(0, 0, 1));
			

			p1.intersect(ray);
			updateIfDistanceChange(ray, maxDistance, col, RGB(1, 1, 0));
			 

			t1.intersect(ray);
			updateIfDistanceChange(ray, maxDistance, col, RGB(0, 1, 1));
			 

			t2.intersect(ray);
			updateIfDistanceChange(ray, maxDistance, col, RGB(1, 1, 1));
		
		

			img.at<Vec3f>(y, x) = col; // store pixel color
		}
	
	img.convertTo(img, CV_8UC3, 255);
	return img;
}

void updateIfDistanceChange(Ray& ray, float& newDistance, Vec3f& oldColor, Vec3f newColor) {
	if (ray.t < newDistance) {
		newDistance = ray.t;
		oldColor = newColor;
	}
}

int main(int argc, char* argv[])
{
	const Size resolution(800, 600);
	// render three images with different camera settings
	
	CCameraPerspective cam1(resolution, Vec3f(0, 0, 10), Vec3f(0, 0, -1), Vec3f(0, 1, 0), 60);
	Mat img1 = RenderFrame(cam1);
	imwrite("perspective1.jpg", img1);
	
	CCameraPerspective cam2(resolution, Vec3f(-8, 3, 8), Vec3f(1, -0.1f, -1), Vec3f(0, 1, 0), 45);
	Mat img2 = RenderFrame(cam2);
	imwrite("perspective2.jpg", img2);
	
	CCameraPerspective cam3(resolution, Vec3f(-8, 3, 8), Vec3f(1, -0.1f, -1), Vec3f(1, 1, 0), 45);
	Mat img3 = RenderFrame(cam3);
	imwrite("perspective3.jpg", img3);

	CCameraEnvironmental cam4(resolution, Vec3f(-8, 3, 8), Vec3f(0, 0, 1), Vec3f(0, 1, 0));
	Mat img4 = RenderFrame(cam4);
	imwrite("environmental4.jpg", img4);

	// AddeEnvironmental camera here as cam4
	// Mat img4 = RenderFrame(cam4);
	// imwrite("orthographic4.jpg", img4);

	return 0;
}
