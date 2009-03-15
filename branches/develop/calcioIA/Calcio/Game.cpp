#include "Game.h"
#include "PlayerAction.h"
#include "AbstractPlayer.h"
#include "Player.h"
#include "Logger.h"

Game::Game(AbstractPlayersFactory& factory1, AbstractPlayersFactory& factory2)
	:	_field(_gameConfiguration.fieldWidth(), _gameConfiguration.fieldHeight(), _gameConfiguration.boxWidthPct(), _gameConfiguration.boxHeightPct()),
		_ball(Point(0.0f,0.0f)), 
		_teamRed(Team::Color_RED, Team::Side_LEFT,factory1),
		_teamBlue(Team::Color_BLUE, Team::Side_RIGHT,factory2)
{

}

const Field& Game::field() const
{
	return _field;
}

const Ball& Game::ball() const
{
	return _ball;
}

void Game::updateGameStatus(Player& player, const PlayerAction& playerAction, const Team& team)
{
	player.position() = player.position() + playerAction.run();
	player.sightDirection(playerAction.sightDirection());

	_ball.move(playerAction.kick());

	const char* teamColor = (team.color() == Team::Color_BLUE) ? "Blue" : "Red";
	LOG_STD << LOG_ELEM(Team, teamColor) << LOG_ELEM(Player, player.abstractPlayer().number());
	LOG_STD << "\t" << LOG_ELEM(Run, playerAction.run())
	LOG_STD << "\t" << LOG_ELEM(Kick, playerAction.kick());
	LOG_STD << "";
}

void Game::updateTeam(const Team& team)
{
	for(Team::PlayersConstIterator pit = team.playersBegin(); pit != team.playersEnd(); ++pit)
	{
		Player* player = *pit;
		PlayerAction action(team.side());
		Perceptions perception(*this, team.color(), *(*pit));
		player->abstractPlayer().run(perception, action);
		updateGameStatus(*player, action, team);
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
