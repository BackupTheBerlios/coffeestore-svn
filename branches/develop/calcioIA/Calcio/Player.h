#ifndef PLAYER_H
#define PLAYER_H

#include "Point.h"
#include "Vector.h"

class AbstractPlayer;

class Player
{
public:
	Player(AbstractPlayer& player);

	AbstractPlayer& abstractPlayer();

	Point& position();
	const Point& position() const;

	void sightDirection(const Vector& dir);
	const Vector& sightDirection() const;

	float radius() const;

private:
	AbstractPlayer& _player;

	Point _position;
	Vector _see;
	float _radius;
};

#endif
