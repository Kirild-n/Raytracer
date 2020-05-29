#include "Scene.h"
#include <cmath>

Scene::Scene(const std::vector<Sphere> &spheres,
			 const LightPoint &light,
			 const Material &background) :
	light(light), spheres(spheres), background(background)
{
}

std::vector<Vec3f> Scene::render(const int width, const int height) const
{
	std::vector<Vec3f> result(width * height);
	const Vec3f origin(Vec3f(0, 0, 0));

	for (size_t i = 0; i < height; i++)
	{
		for (size_t j = 0; j < width; j++)
		{
			float x = (j + 0.5) - width / 2.;
			float y = -(i + 0.5) + height / 2.; 
			float z = -height / (2. * std::tan(1 / 2.)); // fov = 1
			Vec3f destination(x, y, z);
			result[i * width + j] = cast_ray(origin, destination.normalize());
		}
	}

	return result;
}

std::tuple<bool, Vec3f, Vec3f, Material> Scene::scene_intersect(const Vec3f& orig, const Vec3f& dir) const
{
	float min_distance = MAX_DISTANCE;
	auto *result_material = &background;
	Vec3f hit;
	Vec3f N;

	for (const auto &sphere : spheres)
	{
		const auto &[is_intersected, distance] = sphere.ray_intersect(orig, dir);
		if (is_intersected && distance < min_distance)
		{
			min_distance = distance;
			hit = orig + dir * distance;
			N = (hit - sphere.pos()).normalize();
			result_material = &sphere.material();
		}
	}

	return std::tuple { min_distance < MAX_DISTANCE, hit, N, *result_material };
}

Vec3f Scene::cast_ray(const Vec3f& orig, const Vec3f& dir) const
{
	const auto &[is_intersected, point, N, material] = scene_intersect(orig, dir);
	if (!is_intersected)
		return background.color();
		
	Vec3f light_dir = (light.pos() - point).normalize();
	float light_intensity = light.intensity() * std::max(0.f, light_dir * N);

	return material.color() * light_intensity;
}
