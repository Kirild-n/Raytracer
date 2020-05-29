#ifndef SCENE_H
#define SCENE_H

#include "Vec3.h"
#include "Material.h"
#include "LightPoint.h"
#include "Sphere.h"
#include <vector>

class Scene
{
public:
	Scene(const std::vector<Sphere> &spheres,
		  const LightPoint &light,
		  const Material &background = Material(Vec3f(0.14, 0.22, 0.5)));

	std::vector<Vec3f> render(const int width, const int height) const;
private:
	constexpr static float MAX_DISTANCE = 1000;
	const LightPoint light;
	const std::vector<Sphere> spheres;
	const Material background;

	std::tuple<bool, Vec3f, Vec3f, Material> scene_intersect(const Vec3f& orig, const Vec3f& dir) const;

	Vec3f cast_ray(const Vec3f& orig, const Vec3f& dir) const;
};

#endif