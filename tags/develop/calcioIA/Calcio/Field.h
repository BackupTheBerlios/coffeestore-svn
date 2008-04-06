#ifndef FIELD_H
#define FIELD_H

#include "Rectangle.h"
#include "Line.h"

class Field
{
public:
	Field();

	const Rectangle& corner() const;
	const Line& mid() const;
	const Rectangle& boxLeft() const;
	const Rectangle& boxRight() const;

private:
	Rectangle _corner;
	Line _mid;
	Rectangle _boxLeft;
	Rectangle _boxRight;
};

#endif
