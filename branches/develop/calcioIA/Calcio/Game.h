#ifndef GAME_H
#define GAME_H

#include "Field.h"
#include "Ball.h"
#include "Team.h"
#include "Perceptions.h"
#include "GameConfiguration.h"

class PlayerAction;
class AbstractPlayersFactory;
class Player;

class Game
{
public:
	Game(AbstractPlayersFactory& factory1, AbstractPlayersFactory& factory2);

	const Field& field() const;
	const Ball& ball() const;
	
	const Team& teamRed() const;
	const Team& teamBlue() const;

	void update();

private:
	void updateTeam(const Team& team);
	void updateGameStatus(Player& player, const PlayerAction& playerAction, const Team& team);

	GameConfiguration _gameConfiguration;
	Field _field;
	Ball _ball;
	Team _teamRed;
	Team _teamBlue;
};

#endif
