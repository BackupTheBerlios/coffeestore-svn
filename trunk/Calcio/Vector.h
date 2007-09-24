#ifndef VECTOR_H
#define VECTOR_H

#include "Point.h"

class Vector
{
public:
	Vector();
	Vector(float x, float y);
	Vector(const Point& tail, const Point& head);

	float x() const;
	float y() const;

private:
	Point _p;
};

Vector operator * (const Vector& v, float s);

#endif
