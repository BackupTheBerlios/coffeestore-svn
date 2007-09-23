#include "Vector.h"

Vector::Vector()
{

}

Vector::Vector(const Point& tail, const Point& head)
	:	_p(head - tail)
{

}

