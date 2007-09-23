#include "Player.h"
#include <GL/glut.h>
#include <cmath>

Player::Player(const Point& p, int n)
	:	_p(p), _radius(3), _number(n)
{

}

Point& Player::position()
{
	return _p;
}

const Point& Player::position() const
{
	return _p;
}

float Player::radius() const
{
	return _radius;
}

int Player::number() const
{
	return _number;
}

