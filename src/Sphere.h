#ifndef SPHERE_H
#define SPHERE_H

#include "Vec3.h"
#include "Material.h"
#include <tuple>

class Sphere
{
public:
	Sphere(const Vec3f &pos, const float radius, const Material &material);

	const Vec3f &pos() const;

	const float &radius() const;

	const Material &material() const;

	const std::tuple<bool, float> ray_intersect(const Vec3f& orig, const Vec3f& dir) const;

private:
	Vec3f _pos;
	float _radius;
	Material _material;
};

#endif
