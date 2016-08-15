#pragma once

#include "Vector3.h"
#include "Ray.h"

namespace Benzene
{
	class Sphere
	{

		// Center of Sphere
		Vector3f mCenter;

		// Radius and RadiusSquare
		float mRadius, mRadius2;

		// Surface Color
		Vector3f mSurfaceColor;

		// Emission Color
		Vector3f mEmissionColor;

		// Transparancey
		float mTransparancy;

		// Reflection
		float mReflection;

	public:
		Sphere( const Vector3f &c,
				const float &r,
				const Vector3f &sc,
				const float	&refl = 0,
				const float	&trans = 0,
				const Vector3f &ec = Vector3f(0, 0, 0));

		~Sphere(void);

		/*
		Compute a Ray Sphere Intersection using Geometric Solution
		Refer http://www.scratchapixel.com/lessons/3d-basic-rendering/minimal-ray-tracer-rendering-simple-shapes/ray-sphere-intersection
		for meaning of t1, t2
		*/
		bool intersect(	
			//const Vector3f &rayOrigin, 
			//const Vector3f &rayDirection,
			const Ray &incidentRay,
			__out float &t0,							// Output 1
			__out float &t1);							// Output 2


	};
}
