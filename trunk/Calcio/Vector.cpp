#include "Vector.h"

Vector::Vector()
{

}

Vector::Vector(const Point& tail, const Point& head)
	:	_p(head - tail)
{

}

Vector::Vector(float x, float y)
	:	_p(x, y)
{

}

float Vector::x() const
{
	return _p.x();
}

float Vector::y() const
{
	return _p.y();
}

Vector operator * (const Vector& v, float s)
{
	return Vector(v.x() * s, v.y() * s);
}
