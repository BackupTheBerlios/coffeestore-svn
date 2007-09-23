#ifndef PLAYER_H
#define PLAYER_H

#include "Point.h"

class Player
{
public:
	Player(const Point& p, int n);

	Point& position();
	const Point& position() const;

	float radius() const;
	int number() const;

private:
	Point _p;
	float _radius;
	int _number;
};

#endif
