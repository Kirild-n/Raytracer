#include <stdexcept>
#include <cmath>
#include "Vec3.h"

Vec3f::Vec3f(float X, float Y, float Z) : x(X), y(Y), z(Z) {}

Vec3f::Vec3f() = default;

float &Vec3f::operator[](int i)
{
    switch (i)
    {
    case 0:
        return x;
    case 1:
        return y;
    case 2:
        return z;
    default:
        throw std::out_of_range("");
    }
}

const float &Vec3f::operator[](int i) const
{
    switch (i)
    {
    case 0:
        return x;
    case 1:
        return y;
    case 2:
        return z;
    default:
        throw std::out_of_range("");
    }
}

float Vec3f::norm() const
{
    return std::sqrt(x * x + y * y + z * z);
}

Vec3f Vec3f::normalize() const
{
    float nrm = norm();
    return Vec3f(x / nrm, y / nrm, z / nrm);
}

float Vec3f::operator*(const Vec3f &rhs) const
{
	return x * rhs.x + y * rhs.y + z * rhs.z;
}

Vec3f Vec3f::operator+(const Vec3f &rhs) const
{
	return Vec3f(x + rhs.x, y + rhs.y, z + rhs.z);
}

Vec3f Vec3f::operator-(const Vec3f &rhs) const
{
	return Vec3f(x - rhs.x, y - rhs.y, z - rhs.z);
}

Vec3f Vec3f::operator*(const float rhs) const
{
	return Vec3f(x * rhs, y * rhs, z * rhs);
}
