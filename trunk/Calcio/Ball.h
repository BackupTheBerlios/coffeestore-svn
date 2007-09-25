#ifndef BALL_H
#define BALL_H

#include "Circle.h"

class Ball
{
public:
	explicit Ball(const Point& p);

	void move(const Vector& v);

	const Point& position() const;
	const Vector& direction() const;

	float radius() const;

private:
	Circle _ball;
	Vector _d;
};

#endif
