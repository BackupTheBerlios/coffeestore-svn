#include "Game.h"
#include "PlayerAction.h"
#include "Player.h"
#include "Factory.h"

Game::Game(const PlayerFactory& playerFactory)
	:	_playerFactory(playerFactory), _field(), _ball(Point(0.0f,0.0f)), _teamRed(Team::Color_RED), _teamBlue(Team::Color_BLUE)
{
	initPlayers();
}

void Game::initPlayers()
{
	InternalPlayer* player1 = new InternalPlayer(_playerFactory.create(1), 1);
	InternalPlayer* player2 = new InternalPlayer(_playerFactory.create(1), -1);


}

const Field& Game::field() const
{
	return _field;
}

const Ball& Game::ball() const
{
	return _ball;
}

void Game::updateGameStatus(Player& player, const PlayerAction& playerAction)
{

}

void Game::updateTeam(const Team& team)
{
	for(Team::PlayersConstIterator pit = team.playersBegin(); pit != team.playersEnd(); ++pit)
	{
		Player* player = *pit;
		PlayerAction action;
		Perceptions p(*this,*(*pit));
		player->run(p, action);
		updateGameStatus(*player, action);
	}
}

void Game::update()
{
	updateTeam(_teamRed);
	updateTeam(_teamBlue);
}

const Team& Game::teamRed() const
{
	return _teamRed;
}

const Team& Game::teamBlue() const
{
	return _teamBlue;
}
