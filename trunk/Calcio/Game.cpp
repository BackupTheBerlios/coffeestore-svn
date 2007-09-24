#include "Game.h"
#include "PlayerAction.h"
#include "AbstractPlayer.h"
#include "Player.h"

Game::Game(TeamFactory& teamFactory)
	:	_ball(Point(0.0f,0.0f)), _teamRed(Team::Color_RED, Team::Side_LEFT), _teamBlue(Team::Color_BLUE, Team::Side_RIGHT)
{
	initTeams(teamFactory);
}

void Game::initTeams(TeamFactory& teamFactory)
{
	_teamRed.init(teamFactory);
	_teamBlue.init(teamFactory);
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
	player.position().x() += playerAction.run().x();
	player.position().y() += playerAction.run().y();
}

void Game::updateTeam(const Team& team)
{
	for(Team::PlayersConstIterator pit = team.playersBegin(); pit != team.playersEnd(); ++pit)
	{
		Player* player = *pit;
		PlayerAction action(team.side());
		Perceptions perception(*this, team.color(), *(*pit));
		player->abstractPlayer().run(perception, action);
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
