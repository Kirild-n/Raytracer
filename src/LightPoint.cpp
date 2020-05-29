#include "LightPoint.h"


LightPoint::LightPoint(const Vec3f &pos, const float intensity) :
	_pos(pos), _intensity(intensity)
{
}

const Vec3f &LightPoint::pos() const
{
	return _pos;
}

const float &LightPoint::intensity() const
{
	return _intensity;
}
