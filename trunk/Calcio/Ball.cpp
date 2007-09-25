#include "Ball.h"

Ball::Ball(const Point& p)
	:	_ball(p, 1.5f)
{

}

void Ball::move(const Vector& v)
{
	_ball.move(v);
}

const Point& Ball::position() const
{
	return _ball.center();
}

const Vector& Ball::direction() const
{
	return _d;
}

float Ball::radius() const
{
	return _ball.radius();
}
