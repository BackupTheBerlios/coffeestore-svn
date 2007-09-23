#ifndef CONVERTION_H
#define CONVERTION_H

#include "Point.h"
#include "Vector.h"
#include "Team.h"

namespace Convertion
{
	Point toAbsoultePosition(const Point& point, Team::Side side);
	Vector toAbsoultePosition(const Vector& vector, Team::Side side);
	Point toRelativePosition(const Point& point, Team::Side side);
	Vector toRelativePosition(const Vector& vector, Team::Side side);
}

#endif
