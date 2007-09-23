#include "Perceptions.h"
#include "Team.h"
#include "Game.h"
#include "Player.h"
#include "Convertion.h"
#include "AbstractPlayer.h"

Perceptions::Perceptions(const Game& game, Team::Color color, const Player& player)
	:	_player(player),
		_ownTeam((Team::Color_BLUE == color) ? game.teamBlue() : game.teamRed()),
		_opponentTeam((Team::Color_RED == color) ? game.teamBlue() : game.teamRed()),
		_ball(initBall(game))
{
	initOpponentVect(game);
	initTeamMateVect(game);
}

const Point& Perceptions::ballPosition() const
{
	return _ball.position();
}

const Vector& Perceptions::ballDirection() const
{
	return _ball.direction();
}

const Perceptions::PerceivedPlayers& Perceptions::visibleTeamMate() const
{
	return _mate;
}

const Perceptions::PerceivedPlayers& Perceptions::visibleOpponent() const
{
	return _opp;
}

const Point& Perceptions::playerPosition() const
{
	return _player.position();
}

Ball Perceptions::initBall(const Game& game)
{
	return Ball(Convertion::toRelativePosition(game.ball().position(), ownTeamSide()));
}

void Perceptions::initOpponentVect(const Game& game)
{
	for (Team::PlayersConstIterator it = _opponentTeam.playersBegin(); it != _opponentTeam.playersEnd(); it++)
	{
		Player* player = (*it);
		Point position = Convertion::toRelativePosition(player->position(), ownTeamSide());
		_opp.push_back(PerceivedPlayer(position, player->abstractPlayer().number()));
	}
}

void Perceptions::initTeamMateVect(const Game& game)
{
	for (Team::PlayersConstIterator it = _ownTeam.playersBegin(); it != _ownTeam.playersEnd(); it++) // scartare me stesso
	{
		Player* player = (*it);
		Point position = Convertion::toRelativePosition(player->position(), ownTeamSide());
		_mate.push_back(PerceivedPlayer(position, player->abstractPlayer().number()));
	}
}

Team::Color Perceptions::ownTeamColor() const
{
	return _ownTeam.color();
}

Team::Color Perceptions::opponentTeamColor() const
{
	return _opponentTeam.color();
}

Team::Side Perceptions::ownTeamSide() const
{
	return _ownTeam.side();
}

Team::Side Perceptions::opponentTeamSide() const
{
	return _opponentTeam.side();
}
