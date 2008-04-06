#ifndef BALL_H
#define BALL_H

#include "Circle.h"

class Ball
{
public:
	explicit Ball(const Point& p);

	const Point& position() const;
	float radius() const;

	const Vector& direction() const;

	void move(const Vector& v);
	bool contains(const Point& p) const;

private:
	Circle _ball;
	Vector _d;
};

#endif
