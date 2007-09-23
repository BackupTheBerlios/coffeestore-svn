#include "Ball.h"

Ball::Ball(const Point& p)
	:	_p(p), _radius(1.5f)
{

}

Point& Ball::position()
{
	return _p;
}

const Point& Ball::position() const
{
	return _p;
}

Vector& Ball::direction()
{
	return _d;
}

const Vector& Ball::direction() const
{
	return _d;
}

float Ball::radius() const
{
	return _radius;
}
