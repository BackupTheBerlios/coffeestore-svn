#include "Convertion.h"

namespace Convertion
{

Point toAbsoultePosition(const Point& point, Team::Side side)
{
	return 2.0f * (point - Point(100.0f,100.0f)/2.0f) / float(side);
}

Vector toAbsoultePosition(const Vector& vector, Team::Side side)
{
	return vector;
}

Point toRelativePosition(const Point& point, Team::Side side)
{
	return (point * (float)side + Point(100.0f,100.0f))/2.0f;
}

Vector toRelativePosition(const Vector& vector, Team::Side side)
{
	return vector;
}

}
