#include "Game.h"
#include "PlayerAction.h"
#include "AbstractPlayer.h"
#include "Player.h"

Game::Game(PlayerFactory& playerFactory)
	:	_ball(Point(0.0f,0.0f)), _teamRed(Team::Color_RED, Team::Side_LEFT), _teamBlue(Team::Color_BLUE, Team::Side_RIGHT)
{
	initTeams(playerFactory);
}

void Game::initTeams(PlayerFactory& playerFactory)
{
	_teamRed.init(playerFactory);
	_teamBlue.init(playerFactory);
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
	//for(Team::PlayersConstIterator pit = team.playersBegin(); pit != team.playersEnd(); ++pit)
	//{
	//	Player* player = *pit;
	//	PlayerAction action;
	//	Perceptions p(*this,*(*pit));
	//	player->run(p, action);
	//	updateGameStatus(*player, action);
	//}
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
