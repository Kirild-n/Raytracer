#ifndef MATERIAL_H
#define MATERIAL_H

#include "Vec3.h"

class Material
{
public:
	explicit Material(const Vec3f &color = Vec3f(0, 0, 0));

	const Vec3f &color() const;

private:
	Vec3f _color;
};

#endif