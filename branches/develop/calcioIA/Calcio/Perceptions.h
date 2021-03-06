#ifndef PERCEPTIONS_H
#define PERCEPTIONS_H

#include <vector>

#include "Point.h"
#include "Vector.h"
#include "PerceivedPlayer.h"
#include "Ball.h"
#include "Team.h"

class Player;
class Game;
class Field;

class Perceptions
{
public:
	class PositionPct
	{
	public:
		PositionPct(int width, int height);
	
		int width() const;
		int height() const;

	private:
		int _width;
		int _height;
	};

	typedef std::vector<PerceivedPlayer> PerceivedPlayers;

	Perceptions(const Game& game, Team::Color color, const Player& player);

	const Point& ballPosition() const;
	const Vector& ballDirection() const;
	bool isBallkickable() const;

	const PerceivedPlayers& visibleTeamMate() const;
	const PerceivedPlayers& visibleOpponent() const;

	Point playerPosition() const;
	PositionPct playerPositionPct() const;
	Vector playerSightDirection() const;

	Team::Color ownTeamColor() const;
	Team::Color opponentTeamColor() const;
	Team::Side ownTeamSide() const;
	Team::Side opponentTeamSide() const;

private:
	Ball initBall(const Game& game);
	void initOpponentVect(const Game& game);
	void initTeamMateVect(const Game& game);
	
	const Player& _player;
	PerceivedPlayers _mate;
	PerceivedPlayers _opp;

	const Team& _ownTeam;
	const Team& _opponentTeam;
	
	Ball _ball;

	const Field& _field;
};

#endif
