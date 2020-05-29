#ifndef VEC3_H
#define VEC3_H

struct Vec3f
{
	Vec3f(float X, float Y, float Z);

	Vec3f();

	float &operator[](int i);
    
    const float &operator[](int i) const;

	float norm() const;

	Vec3f normalize() const;

    float operator*(const Vec3f &rhs) const;

    Vec3f operator+(const Vec3f &rhs) const;

    Vec3f operator-(const Vec3f &rhs) const;

    Vec3f operator*(const float rhs) const;

	float x, y, z;
};

#endif