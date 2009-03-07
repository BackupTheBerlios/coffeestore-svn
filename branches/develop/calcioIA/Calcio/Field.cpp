#include "Field.h"

Field::Field(int fieldWidth, int fieldHeight, int boxWidthPct, int boxHeightPct)
	:	_corner(createCorner(fieldWidth, fieldHeight)),
		_mid(createMid(fieldHeight)),
		_boxLeft(createBoxLeft(fieldWidth, fieldHeight, boxWidthPct, boxHeightPct)),
		_boxRight(createBoxRigth(fieldWidth, fieldHeight, boxWidthPct, boxHeightPct))
		
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

Point Field::getBoxDelta(int fieldWidth, int fieldHeight, int boxWidthPct, int boxHeightPct) const
{
	float heightPct  = (100.0f - boxHeightPct) / 2.0f;
	float widthPct = (float) boxWidthPct;

	float dheight = (fieldHeight * heightPct) / 100.0f;
	float dwidth = ((fieldWidth/2.0f) * widthPct) / 100.0f;

	return Point(dwidth, dheight);
}

Rectangle Field::createBoxLeft(int fieldWidth, int fieldHeight, int boxWidthPct, int boxHeightPct) const
{
	Point corner_a(-fieldWidth/2.0f, -fieldHeight/2.0f);
	Point corner_d(-fieldWidth/2.0f, fieldHeight/2.0f);
	Point delta = getBoxDelta(fieldWidth, fieldHeight, boxWidthPct, boxHeightPct);

	Point a(corner_a.x(), corner_a.y() + delta.y());
	Point c(corner_d.x() + delta.x(), corner_d.y() - delta.y());
	return Rectangle(a, c);
}

Rectangle Field::createBoxRigth(int fieldWidth, int fieldHeight, int boxWidthPct, int boxHeightPct) const
{
	Point corner_b(fieldWidth/2.0f, -fieldHeight/2.0f);
	Point corner_c(fieldWidth/2.0f, fieldHeight/2.0f);

	Point delta = getBoxDelta(fieldWidth, fieldHeight, boxWidthPct, boxHeightPct);

	Point a(corner_b.x() - delta.x(), corner_b.y() + delta.y());
	Point c(corner_c.x(), corner_c.y() - delta.y());
	return Rectangle(a, c);
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
