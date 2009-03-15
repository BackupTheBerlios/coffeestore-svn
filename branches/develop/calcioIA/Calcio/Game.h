#ifndef GAME_H
#define GAME_H

#include "Ball.h"
#include "Team.h"
#include "Perceptions.h"

class PlayerAction;
class AbstractPlayersFactory;
class Player;
class Field;

class Game
{
public:
	Game(const Field& field, AbstractPlayersFactory& factoryRed, AbstractPlayersFactory& factoryBlue);

	const Field& field() const;
	const Ball& ball() const;
	
	const Team& teamRed() const;
	const Team& teamBlue() const;

	void update();

private:
	void updateTeam(const Team& team);
	void updateGameStatus(Player& player, const PlayerAction& playerAction);

	const Field& _field;
	Ball _ball;
	Team _teamRed;
	Team _teamBlue;
};

#endif
