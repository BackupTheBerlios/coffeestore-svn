#include "Circle.h"

Circle::Circle(const Point& center, float radius)	
	:	_center(center), _radius(radius)
{

}

float Circle::radius() const
{
	return _radius;
}

const Point& Circle::center() const
{
	return _center;
}

void Circle::move(const Vector& v)
{
	_center.x() += v.x();
	_center.y() += v.y();
}

bool Circle::contained(const Point& point) const
{
	Point diff = point - _center;
	return false; //.abs() <= radius;
}
