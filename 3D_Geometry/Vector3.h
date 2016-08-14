#pragma once
/*
	Reference Used ScratchPixel
*/

#include <math.h>
#include <iostream>

template <typename T>
class Vector3
{
	T x, y, z;

public:
	Vector3();
	Vector3(T in_x,T in_y,T in_z);
	~Vector3(void);

	T length();
	Vector3<T>& normalize();

	T dot(const Vector3<T> &v) const;
	Vector3<T> cross(const Vector3<T> &v) const;
	
	Vector3<T> operator + (const Vector3<T> &v) const; 
	Vector3<T> operator - (const Vector3<T> &v) const;
	Vector3<T> operator * (const T &r) const;

	const T& operator[](int i) const
	{
		return (&x)[i];
	}

	//friend std::ostream& operator << (std::ostream &s, const Vec3<T> &v)
	//{
	//	return s << '(' << v.x << ' ' << v.y << ' ' << v.z << ')';
	//}

};

template <typename T>
Vector3<T>::Vector3(T in_x, T in_y, T in_z):x(in_x), y(in_y), z(in_z)
{
}

template <typename T>
Vector3<T>::~Vector3(void)
{
}

template <typename T>
Vector3<T>::Vector3():x(T(0)), y(T(0)), z(T(0))
{
}

template <typename T>
T Vector3<T>::length()
{
	return sqrt(x * x + y * y + z * z);
}


 // as a method of the class Vector3
template <typename T>
Vector3<T>& Vector3<T>::normalize()
{
	T len = length();
	if (len > 0)
	{
		T invLen = 1 / len;
		x *= invLen, y *= invLen, z *= invLen;
	}

	return *this;
} 

template <typename T>
T Vector3<T>::dot(const Vector3<T> &v) const
{
	return x * v.x + y * v.y + z * v.z;
}

template <typename T>
Vector3<T> Vector3<T>::cross(const Vector3<T> &v) const
{
	return Vector3<T>(
	y * v.z - z * v.y,
	z * v.x - x * v.z,
	x * v.y - y * v.x);
}
						
template <typename T>
Vector3<T> Vector3<T>::operator+(const Vector3<T> &v) const		
{ return Vector3<T>(x + v.x, y + v.y, z + v.z); }

template <typename T>
Vector3<T> Vector3<T>::operator-(const Vector3<T> &v) const
{ return Vector3<T>(x - v.x, y - v.y, z - v.z); }

template <typename T>
Vector3<T> Vector3<T>::operator*(const T &r) const
{ return Vector3<T>(x * r, y * r, z * r); } 



typedef Vector3<float> Vector3f;
typedef Vector3<int> Vector3i;