#include "Vector.h"
#include <cmath>


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

float Vector::length() const
{
	return sqrt(x()*x() + y()*y());
}

Vector Vector::normalize() const
{

	return Vector(*this / length());
}

Vector& Vector::operator=( const Vector& v )
{
	_p.x() = v.x();
	_p.y() = v.y();
	return *this;
}

Vector operator * (const Vector& v, float s)
{
	return Vector(v.x() * s, v.y() * s);
}

Vector operator * (float s, const Vector& v)
{
	return Vector(v.x() * s, v.y() * s);
}

Vector operator + (const Vector& v,const Point& p)
{
	return Vector(v.x() + p.x(), v.y() + p.y());
}

Vector operator + (const Point& p,const Vector& v)
{
	return Vector(v.x() + p.x(), v.y() + p.y());
}

Vector operator / (const Vector& v, float s)
{
	return Vector(v.x() / s, v.y() / s);
}

