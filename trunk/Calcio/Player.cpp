#include "Player.h"
#include <GL/glut.h>
#include <cmath>

Player::Player(const Point& p, int n)
	:	_p(p), _number(n)
{
	_radius = 3;
}

void Player::draw()
{
	const float deg2rad = 3.14159/180;

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();

	glScalef(450.0f/800.0f,1.0f,1.0f);
	glTranslatef(_p.x(), _p.y(), 0.0f);

	glBegin(GL_POLYGON);

	for (int i = 0; i < 360; i++)
	{
		float degInRad = i*deg2rad;
		glVertex2f(cos(degInRad)*_radius, sin(degInRad)*_radius);
	}

	glEnd();
	
	glPopMatrix();
}

int Player::number() const
{
	return _number;
}

Point& Player::position()
{
	return _p;
}

const Point& Player::position() const
{
	return _p;
}
