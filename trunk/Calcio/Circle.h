#ifndef CIRCLE_H
#define CIRCLE_H

#include "Point.h"
#include "Vector.h"

class Circle
{
public:
	Circle(const Point& center, float radius);

	float radius() const;
	const Point& center() const;

	void move(const Vector& v);

	bool contained(const Point& point) const;
private:
	float _radius;
	Point _center;
};

#endif


