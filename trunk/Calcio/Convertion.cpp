#include "Convertion.h"

namespace Convertion
{

Point toAbsoultePosition(const Point& point, Team::Side side)
{
	return Point(point.x()*side, point.y()*side);
}

Vector toAbsoultePosition(const Vector& vector, Team::Side side)
{
	return vector;
}

Point toRelativePosition(const Point& point, Team::Side side)
{
	return point;
}

Vector toRelativePosition(const Vector& vector, Team::Side side)
{
	return vector;
}

}
