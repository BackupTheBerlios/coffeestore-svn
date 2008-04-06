#ifndef PLAYER_H
#define PLAYER_H

#include "Point.h"

class AbstractPlayer;

class Player
{
public:
	Player(AbstractPlayer& player);

	AbstractPlayer& abstractPlayer();

	Point& position();
	const Point& position() const;

	float radius() const;

private:
	AbstractPlayer& _player;

	Point _position;
	float _radius;
};

#endif
