#include "Vector.h"
#include <cmath>
#include <ostream>

Vector::Vector()
{

}

Vector::Vector(const Point& tail, const Point& head)
	:	_p(head.x() - tail.x(),head.y() - tail.y())
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
	return *this / length();
}

Vector operator * (const Vector& v, float s)
{
	return Vector(v.x() * s, v.y() * s);
}

Vector operator * (float s, const Vector& v)
{
	return Vector(v.x() * s, v.y() * s);
}

Point operator + (const Vector& v,const Point& p)
{
	return Point(v.x() + p.x(),v.y() + p.y());
}

Point operator + (const Point& p,const Vector& v)
{
	return Point(v.x() + p.x(),v.y() + p.y());
}

Vector operator+( const Vector& v1,const Vector& v2 )
{
	return Vector(v1.x() + v2.x(),v1.y() + v2.y());
}
Vector operator - (const Point& p1, const Point& p2)
{
	return Vector(p1.x() - p2.x(), p1.y() - p2.y());
}


Vector operator / (const Vector& v, float s)
{
	return Vector(v.x() / s, v.y() / s);
}

std::ostream& operator << (std::ostream& os, const Vector& v)
{
	os << v._p;
	return os;
}
