#ifndef MATHFUN_H
#define MATHFUN_H

#include <cmath>

#ifndef M_PI
#define M_PI  3.14159265358979323846
#endif

namespace mathfun
{
	float deg2Rad(const float deg)
	{
		return float(M_PI) * deg / 180.0f;
	}

	float rad2Deg(const float rad)
	{
		return 180.0f * rad / float(M_PI);
	}
}

#endif MATHFUN_H