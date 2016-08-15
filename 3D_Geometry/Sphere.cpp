#include "Sphere.h"


namespace Benzene
{

	Sphere::Sphere(
			const Vector3f &c,
			const float &r,
			const Vector3f &sc,
			const float	&refl = 0,
			const float	&trans = 0,
			const Vector3f &ec = Vector3f(0, 0, 0)):
	mCenter(c), mRadius(r), mRadius2(r*r), mSurfaceColor(sc),
		mEmissionColor(ec), mReflection(refl), mTransparancy(trans)
	{}

	Sphere::~Sphere(void)
	{
	}

	bool Sphere::intersect(const Ray &incidentRay, __out float &t0, __out float &t1)
	{

	}
};
