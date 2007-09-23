#ifndef BALL_H
#define BALL_H

#include "Point.h"
#include "Vector.h"

class Ball
{
public:
	explicit Ball(const Point& p);

	Point& position();
	const Point& position() const;
	Vector& direction();
	const Vector& direction() const;

	float radius() const;

private:
	Point _p;
	Vector _d;
	float _radius;
};

#endif
