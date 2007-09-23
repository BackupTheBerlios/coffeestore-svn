#include "Field.h"
#include <GL/glut.h>

Field::Field()
	:	_corner(Point(-100.0f,-100.0f), Point(100.0f,100.0f)),
		_mid(Point(0.0f,100.0f), Point(0.0f,-100.0f)),
		_boxLeft(Point(-100.0f,-65.0f), Point(-70.0f,65.0f)),
		_boxRight(Point(70.0f,-65.0f), Point(100.0f,65.0f))
		
{

}

const Rectangle& Field::corner() const
{
	return _corner;
}

const Line& Field::mid() const
{
	return _mid;
}

const Rectangle& Field::boxLeft() const
{
	return _boxLeft;
}

const Rectangle& Field::boxRight() const
{
	return _boxRight;
}

