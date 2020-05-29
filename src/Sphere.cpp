#include "Sphere.h"
#include <cmath>

Sphere::Sphere(const Vec3f &pos,
   		       const float radius,
			   const Material &material) :
	_pos(pos), _radius(radius), _material(material)
{
}

const Vec3f &Sphere::pos() const 
{
	return _pos;
}

const float &Sphere::radius() const
{
	return _radius;
}

const Material &Sphere::material() const
{
	return _material;
}

const std::tuple<bool, float> Sphere::ray_intersect(const Vec3f& orig, const Vec3f& dir) const
{
	Vec3f L = _pos - orig;
	float tca = L * dir;
	float d2 = L * L - tca * tca;
	if (d2 > _radius * _radius)
		return std::tuple { false, 0 };

	float thc = std::sqrt(_radius * _radius - d2);
	float t0 = tca - thc;
	if (t0 >= 0)
		return std::tuple { true, t0 };
	else
		return std::tuple { false, 0 };
}
