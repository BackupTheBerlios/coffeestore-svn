#ifndef PERCEPTIONS_H
#define PERCEPTIONS_H

#include <vector>

#include "Point.h"
#include "Vector.h"
#include "PerceivedPlayer.h"
#include "Ball.h"

class Player;
class Game;

class Perceptions
{
public:
	typedef std::vector<PerceivedPlayer> PerceivedPlayers;
	Perceptions(const Game& game,const Player& ply);

	const Point& ballPosition() const;
	const Vector& ballDirection() const;

	const PerceivedPlayers& visibleTeamMate() const;
	const PerceivedPlayers& visibleOpponent() const;

	const Point& playerPosition() const;

private:
	Ball initBall(const Game& game);
	void initOpponentVect(const Game& game);
	void initTeamMateVect(const Game& game);
	
	const Player& _player;
	Ball _ball;
	PerceivedPlayers _mate;
	PerceivedPlayers _opp;
};

#endif
