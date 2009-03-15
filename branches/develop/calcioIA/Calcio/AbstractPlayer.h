#ifndef ABSTARCT_PLAYER_H
#define ABSTARCT_PLAYER_H

#include "Point.h"

class PlayerAction;
class Perceptions;

class AbstractPlayer
{
public:
	AbstractPlayer(const Point& initialPosition, int number);
	virtual ~AbstractPlayer() {}

	const Point& initialPosition() const;
	int number() const;

	virtual void run(const Perceptions& perceptions, PlayerAction& playerAction) = 0;

private:
	Point _initialPosition;
	int _number;
};

#endif
