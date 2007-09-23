#ifndef PLAYER_H
#define PLAYER_H

#include "Point.h"

class PlayerAction;
class Perceptions;

class Player
{
public:
	Player(const Point& initialPosition, int number);

	const Point& position() const;
	int number() const;

	virtual void run(const Perceptions& perceptions, PlayerAction& playerAction) = 0;

private:
	Point _initialPosition;
	int _number;
};

#endif
