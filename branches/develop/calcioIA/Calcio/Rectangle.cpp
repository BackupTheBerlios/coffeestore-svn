#include "Rectangle.h"
#include <string>

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

bool operator == (const Rectangle& rectangle1, const Rectangle& rectangle2)
{
	return rectangle1.a() == rectangle2.a() && rectangle1.c() == rectangle2.c();
}

std::ostream& operator << (std::ostream& os, const Rectangle& rectangle)
{
	os << "a[" << rectangle.a() << "],c[" << rectangle.c() << "]";
	return os;
}