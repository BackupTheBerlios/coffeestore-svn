#include "Field.h"

Field::Field(int fieldWidth, int fieldHeight)
	:	_corner(createCorner(fieldWidth, fieldHeight)),
		_mid(createMid(fieldHeight)),
		_boxLeft(Point(-100.0f,-65.0f), Point(-70.0f,65.0f)),
		_boxRight(Point(70.0f,-65.0f), Point(100.0f,65.0f))
		
{

}

Rectangle Field::createCorner(int fieldWidth, int fieldHeight) const
{
	Point a(-fieldWidth/2.0f, -fieldHeight/2.0f);
	Point c(fieldWidth/2.0f, fieldHeight/2.0f);
	return Rectangle(a, c);
}

Line Field::createMid(int fieldHeight) const
{
	Point a(0.0f, fieldHeight/2.0f);
	Point b(0.0f, -fieldHeight/2.0f);
	return Line(a, b);
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
