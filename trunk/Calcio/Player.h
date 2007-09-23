#ifndef PLAYER_H
#define PLAYER_H

#include "Point.h"

class Player
{
public:
	Player(const Point& p, int n);

	void draw();

	int number() const;
	Point& position();
	const Point& position() const;

private:
	Point _p;
	float _radius;
	int _number;
};

#endif
