#ifndef PLAYER_H
#define PLAYER_H

#include "Point.h"
#include "Team.h"

class PlayerAction;
class Perceptions;

class Player
{
public:
	Player(const Point& p, int n, Team::Color color);

	Point& position();
	const Point& position() const;

	float radius() const;
	int number() const;

	Team::Color teamColor() const;

	virtual void run(const Perceptions& p, PlayerAction& playerAction);

private:
	Point _p;
	float _radius;
	int _number;
	Team::Color _teamColor;
};

#endif
