#include "Material.h"

Material::Material(const Vec3f &color) :
	_color(color)
{
}

const Vec3f &Material::color() const
{
	return _color;
}
