#include "Ball.h"
#include <GL/glut.h>
#include <cmath>

Ball::Ball(const Point& p)
:	_p(p)
{
	_radius = 1.5f;
}

void Ball::draw()
{
	const float deg2rad = 3.14159/180;

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();

	glScalef(450.0f/800.0f,1.0f,1.0f);
	glTranslatef(_p.x(), _p.y(), 0.0f);

	glPushAttrib(GL_CURRENT_BIT);

	glColor3f(1.0f, 1.0f, 1.0f);

	glBegin(GL_POLYGON);

	for (int i = 0; i < 360; i++)
	{
		float degInRad = i*deg2rad;
		glVertex2f(cos(degInRad)*_radius, sin(degInRad)*_radius);
	}

	glEnd();

	glPopAttrib();

	glPopMatrix();
}

Point& Ball::position()
{
	return _p;
}

const Point& Ball::position() const
{
	return _p;
}
