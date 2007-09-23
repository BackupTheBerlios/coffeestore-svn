#ifndef GAME_H
#define GAME_H

#include "Field.h"
#include "Ball.h"
#include "Team.h"
#include "Perceptions.h"

class PlayerAction;
class PlayerFactory;
class Player;

class Game
{
public:
	Game(PlayerFactory& playerFactory);

	const Field& field() const;
	const Ball& ball() const;
	
	const Team& teamRed() const;
	const Team& teamBlue() const;

	void update();

private:
	void initTeams(PlayerFactory& playerFactory);

	void updateTeam(const Team& team);
	void updateGameStatus(Player& player, const PlayerAction& playerAction);

	Field _field;
	Ball _ball;
	Team _teamRed;
	Team _teamBlue;
};

#endif
