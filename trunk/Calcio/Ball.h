#ifndef BALL_H
#define BALL_H

#include "Point.h"

class Ball
{
public:
	explicit Ball(const Point& p);

	Point& position();
	const Point& position() const;
	float radius() const;

private:
	Point _p;
	float _radius;
};

#endif
