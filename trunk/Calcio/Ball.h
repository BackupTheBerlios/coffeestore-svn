#ifndef BALL_H
#define BALL_H

#include "Point.h"

class Ball
{
public:
	Ball(const Point& p);

	void draw();

	Point& position();
	const Point& position() const;

private:
	Point _p;
	float _radius;
};

#endif


