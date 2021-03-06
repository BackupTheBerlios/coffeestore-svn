#ifndef FIELD_H
#define FIELD_H

#include "Rectangle.h"
#include "Line.h"

class Field
{
public:
	Field(int fieldWidth, int fieldHeight, int boxWidthPct, int boxHeighPct);

	const Rectangle& corner() const;
	const Line& mid() const;
	const Rectangle& boxLeft() const;
	const Rectangle& boxRight() const;

private:
	Rectangle createCorner(int fieldWidth, int fieldHeight) const;
	Line createMid(int fieldHeight) const;
	Rectangle createBoxLeft(int fieldWidth, int fieldHeight, int boxWidthPct, int boxHeightPct) const;
	Rectangle createBoxRigth(int fieldWidth, int fieldHeight, int boxWidthPct, int boxHeightPct) const;
	Point getBoxDelta(int fieldWidth, int fieldHeight, int boxWidthPct, int boxHeightPct) const;

	Rectangle _corner;
	Line _mid;
	Rectangle _boxLeft;
	Rectangle _boxRight;
};

#endif
