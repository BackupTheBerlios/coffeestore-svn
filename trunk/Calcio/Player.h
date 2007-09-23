#ifndef PLAYER_H
#define PLAYER_H

#include "Point.h"

class AbstractPlayer;

class Player
{
public:
	Player(const AbstractPlayer& player);

	const AbstractPlayer& abstractPlayer() const;

	Point& position();
	const Point& position() const;

	float radius() const;

private:
	const AbstractPlayer& _player;

	Point _position;
	float _radius;
};

#endif
