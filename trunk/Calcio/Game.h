#ifndef GAME_H
#define GAME_H

#include "Field.h"
#include "Ball.h"
#include "Team.h"
#include "Perceptions.h"

class PlayerAction;

class Game
{
public:
	Game();

	const Perceptions& perceptions() const;
	const Field& field() const;
	const Ball& ball() const;
	const Team& team(const Team::Color col) const;

	void update();

private:
	void updateTeam(const Team& team);
	void updateGameStatus(Player& player, const PlayerAction& playerAction);

	Field _field;
	Ball _ball;
	Team _teamRed;
	Team _teamBlue;
	Perceptions _perceptions;
};

#endif
