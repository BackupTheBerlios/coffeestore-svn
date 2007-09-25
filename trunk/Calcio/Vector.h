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

	float length() const;
	Vector normalize() const;

	Vector& operator= (const Vector& v);

private:
	Point _p;
};

Vector operator - (const Point& p1, const Point& p2);
Vector operator * (const Vector& v, float s);
Vector operator * (float s,const Vector& v);
Point operator + (const Vector& v,const Point& p);
Point operator + (const Point& p,const Vector& v);
Vector operator + (const Vector& v1,const Vector& v2);
Vector operator / (const Vector& v, float s);


#endif
