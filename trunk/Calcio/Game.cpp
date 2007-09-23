#include "Game.h"
#include "PlayerAction.h"
#include "Player.h"

Game::Game()
	:	_field(), _ball(Point(0.0f,0.0f)), _teamRed(Team::Color_RED), _teamBlue(Team::Color_BLUE)
{
	_perceptions._game = this;
}

const Perceptions& Game::perceptions() const
{
	return _perceptions;
}

const Field& Game::field() const
{
	return _field;
}

const Ball& Game::ball() const
{
	return _ball;
}

const Team& Game::team(const Team::Color col) const
{
	return (col == Team::Color_RED) ? _teamRed : _teamBlue;
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
		player->run(_perceptions, action);
		updateGameStatus(*player, action);
	}
}

void Game::update()
{
	updateTeam(_teamRed);
	updateTeam(_teamBlue);
}
