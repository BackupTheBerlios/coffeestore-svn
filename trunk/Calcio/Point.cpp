#include "Point.h"

Point::Point()
{
	set(0,0);
}

Point::Point(float x, float y)
{
	set(x,y);
}

float Point::x() const
{
	return _p[0];
}

float Point::y() const
{
	return _p[1];
}

float& Point::x()
{
	return _p[0];
}

float& Point::y()
{
	return _p[1];
}

void Point::set(float x, float y)
{
	_p[0] = x;
	_p[1] = y;
}

Point operator - (const Point& p1, const Point& p2)
{
	return Point(p1.x() - p2.x(), p1.y() - p2.y());
}

