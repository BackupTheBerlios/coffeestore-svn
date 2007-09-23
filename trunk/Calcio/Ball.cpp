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

float Ball::radius() const
{
	return _radius;
}
