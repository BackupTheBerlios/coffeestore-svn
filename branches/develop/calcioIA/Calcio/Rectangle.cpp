#include "Rectangle.h"

Rectangle::Rectangle(const Point& a, const Point& c)
	:	_a(a), _c(c)
{

}

const Point& Rectangle::a() const
{
	return _a;
}

const Point& Rectangle::c() const
{
	return _c;
}
