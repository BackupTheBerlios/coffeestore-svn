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

Rectangle Field::createBoxLeft(int fieldWidth, int fieldHeight, int boxWidthPct, int boxHeightPct) const
{
	float corner_ax = -fieldWidth/2.0f;
	float corner_ay = -fieldHeight/2.0f;
	float corner_dx = -fieldWidth/2.0f;
	float corner_dy = fieldHeight/2.0f;

	float heightPct  = (100.0f - boxHeightPct) / 2.0f;
	float widthPct = boxWidthPct;

	float dheight = (fieldHeight * heightPct) / 100.0f;
	float dwidth = ((fieldWidth/2.0f) * widthPct) / 100.0f;

	Point a(corner_ax, corner_ay + dheight);
	Point c(corner_dx + dwidth, corner_dy - dheight);
	return Rectangle(a, c);
}

Rectangle Field::createBoxRigth(int fieldWidth, int fieldHeight, int boxWidthPct, int boxHeightPct) const
{
	float corner_bx = fieldWidth/2.0f;
	float corner_by = -fieldHeight/2.0f;
	float corner_cx = fieldWidth/2.0f;
	float corner_cy = fieldHeight/2.0f;

	float heightPct  = (100.0f - boxHeightPct) / 2.0f;
	float widthPct = boxWidthPct;

	float dheight = (fieldHeight * heightPct) / 100.0f;
	float dwidth = ((fieldWidth/2.0f) * widthPct) / 100.0f;

	Point a(corner_bx - dwidth, corner_by + dheight);
	Point c(corner_cx, corner_cy - dheight);
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
