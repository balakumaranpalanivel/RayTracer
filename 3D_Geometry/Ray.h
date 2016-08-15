#pragma once

#include "Vector3.h"

namespace Benzene
{
	class Ray
	{
	public:
		Vector3f mRayOrigin;
		Vector3f mRayDirection;

		Ray(const Vector3f &rayOrig,
			const Vector3f &rayDir);

		~Ray(void);

	};
}
