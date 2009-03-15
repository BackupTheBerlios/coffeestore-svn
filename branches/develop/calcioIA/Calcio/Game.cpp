#include "Game.h"
#include "PlayerAction.h"
#include "AbstractPlayer.h"
#include "Player.h"
#include "Field.h"
#include "Logger.h"

Game::Game(const Field& field, AbstractPlayersFactory& factoryRed, AbstractPlayersFactory& factoryBlue)
	:	_field(field),
		_ball(Point(0.0f,0.0f)), 
		_teamRed(Team::Color_RED, Team::Side_LEFT, factoryRed),
		_teamBlue(Team::Color_BLUE, Team::Side_RIGHT, factoryBlue)
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

void Game::updateGameStatus(Player& player, const PlayerAction& playerAction)
{
	player.position() = player.position() + playerAction.run();
	player.sightDirection(playerAction.sightDirection());

	_ball.move(playerAction.kick());
}

void Game::updateTeam(const Team& team)
{
	for(Team::PlayersConstIterator pit = team.playersBegin(); pit != team.playersEnd(); ++pit)
	{
		Player* player = *pit;
		PlayerAction action(team.side());
		Perceptions perception(*this, team.color(), *(*pit));
		player->abstractPlayer().run(perception, action);
		
		const char* teamColor = (team.color() == Team::Color_BLUE) ? "Blue" : "Red";
		LOG_STD << LOG_ELEM(Team, teamColor) << LOG_ELEM(Player, player->abstractPlayer().number()) << LOG_ELEM(Type, typeid(player->abstractPlayer()).name());
		LOG_STD << "\t" << LOG_ELEM(Run, action.run());
		LOG_STD << "\t" << LOG_ELEM(Kick, action.kick());
		LOG_STD << "\t" << LOG_ELEM(AbsolutePos, player->position());
		LOG_STD << "\t" << LOG_ELEM(RelativePos, perception.playerPosition());
		LOG_STD << "\t" << "RelativePosPct [" << perception.playerPositionPct().width() << ", " << perception.playerPositionPct().height() << "] ";
		LOG_STD << "";
		
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
