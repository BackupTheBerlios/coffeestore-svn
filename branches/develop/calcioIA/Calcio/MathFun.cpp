#include "MathFun.h"
#include <math.h>

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

