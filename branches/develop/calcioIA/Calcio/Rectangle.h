#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Point.h"

//	d----c
//	|    |
//	a----b

class Rectangle
{
public:
	Rectangle(const Point& a, const Point& c);

	const Point& a() const;
	const Point& c() const;

private:
	Point _a;
	Point _c;
};

#endif
