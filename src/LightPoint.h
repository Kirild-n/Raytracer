#ifndef LIGHT_POINT_H
#define LIGHT_POINT_H

#include "Vec3.h"

class LightPoint
{
public:
	LightPoint(const Vec3f &pos, const float intensity);
	const Vec3f &pos() const;
	const float &intensity() const;
private:
	Vec3f _pos;
	float _intensity;
};

#endif