#ifndef PERCEPTIONS_H
#define PERCEPTIONS_H

#include "Point.h"
#include "Vector.h"
#include "Team.h"

class Player;
class Game;

class Perceptions
{
	friend class Game;
public:
	Perceptions();

	const Point& ballPosition() const;
	const Vector& ballDirection() const;

	Team::Players visibleTeamMate(const Player& player) const;
	Team::Players visibleOpponent(const Player& player) const;

private:
	const Game* _game;
};

#endif
