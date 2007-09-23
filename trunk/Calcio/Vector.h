#ifndef VECTOR_H
#define VECTOR_H

#include "Point.h"

class Vector
{
public:
	Vector();
	Vector(const Point& tail, const Point& head);

private:
	Point _p;
};

#endif
