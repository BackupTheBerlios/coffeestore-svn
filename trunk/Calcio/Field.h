#ifndef FIELD_H
#define FIELD_H

#include "Point.h"

class Field
{
public:
	Field();

	void draw();

private:
	void drawLoop(Point* points, int size);

	Point _corner[4];
	Point _mid[2];
	Point _boxLeft[4];
	Point _boxRight[4];
};

#endif
