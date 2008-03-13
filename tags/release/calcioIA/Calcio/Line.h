#ifndef LINE_H
#define LINE_H

#include "Point.h"

class Line
{
public:
	Line(const Point& a, const Point& b);

	const Point& a() const;
	const Point& b() const;

private:
	Point _a;
	Point _b;
};

#endif
