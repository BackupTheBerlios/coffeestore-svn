#include "Line.h"

Line::Line(const Point& a, const Point& b)
	:	_a(a), _b(b)
{

}

const Point& Line::a() const
{
	return _a;
}

const Point& Line::b() const
{
	return _b;
}
