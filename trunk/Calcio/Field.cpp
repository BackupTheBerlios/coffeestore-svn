#include "Field.h"
#include <GL/glut.h>

Field::Field()
{
	_corner[0].set(-100.0f,-100.0f);
	_corner[1].set(100.0f,-100.0f);
	_corner[2].set(100.0f,100.0f);
	_corner[3].set(-100.0f,100.0f);

	_mid[0].set(0.0f,100.0f);
	_mid[1].set(0.0f,-100.0f);

	_boxLeft[0].set(-100.0f,-65.0f);
	_boxLeft[1].set(-70.0f,-65.0f);
	_boxLeft[2].set(-70.0f,65.0f);
	_boxLeft[3].set(-100.0f,65.0f);

	_boxRight[0].set(70.0f,-65.0f);
	_boxRight[1].set(100.0f,-65.0f);
	_boxRight[2].set(100.0f,65.0f);
	_boxRight[3].set(70.0f,65.0f);
}

void Field::drawLoop(Point* points, int size)
{
	glPushAttrib(GL_CURRENT_BIT);
	glColor3f(1.0f,1.0f,1.0f);

	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < size; i++)
		glVertex2fv(points[i]);
	glEnd();

	glPopAttrib();
}

void Field::draw()
{
	drawLoop(_corner, 4);
	drawLoop(_mid, 2);
	drawLoop(_boxLeft, 4);
	drawLoop(_boxRight, 4);
}
