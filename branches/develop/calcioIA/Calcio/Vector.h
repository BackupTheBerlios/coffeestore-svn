#ifndef VECTOR_H
#define VECTOR_H

#include "Point.h"

class Vector
{
	friend std::ostream& operator << (std::ostream& os, const Vector& v);
public:
	Vector();
	Vector(float x, float y);
	Vector(const Point& tail, const Point& head);

	float x() const;
	float y() const;

	float length() const;
	Vector normalize() const;

private:
	Point _p;
};

Vector operator - (const Point& p1, const Point& p2);
Vector operator * (const Vector& v, float s);
Vector operator * (float s,const Vector& v);
float operator * (const Vector& v0,const Vector& v1);
Point operator + (const Vector& v,const Point& p);
Point operator + (const Point& p,const Vector& v);
Vector operator + (const Vector& v1,const Vector& v2);
Vector operator / (const Vector& v, float s);

std::ostream& operator << (std::ostream& os, const Vector& v);

#endif
