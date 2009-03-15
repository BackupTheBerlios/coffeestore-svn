#include "Perceptions.h"
#include "Team.h"
#include "Game.h"
#include "Player.h"
#include "Convertion.h"
#include "Field.h"
#include "AbstractPlayer.h"
#include <cmath>

Perceptions::Perceptions(const Game& game, Team::Color color, const Player& player)
	:	_player(player),
		_ownTeam((Team::Color_BLUE == color) ? game.teamBlue() : game.teamRed()),
		_opponentTeam((Team::Color_RED == color) ? game.teamBlue() : game.teamRed()),
		_ball(initBall(game)),
		_field(game.field())
{
	initOpponentVect(game);
	initTeamMateVect(game);
}

Perceptions::PositionPct::PositionPct(int width, int height)
	:	_width(width), _height(height)
{

}

int Perceptions::PositionPct::width() const
{
	return _width;
}

int Perceptions::PositionPct::height() const
{
	return _height;
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

Point Perceptions::playerPosition() const
{
	return Convertion::toRelativePosition(_player.position(), ownTeamSide());
}

Perceptions::PositionPct Perceptions::playerPositionPct() const
{
	Point start = _field.corner().a();
	Point end = _field.corner().c();
	Point pos = _player.position();

	float widthPct = (100.0f * (ownTeamSide() * pos.x() + -1.0f * start.x())) / (-1.0f * start.x() + end.x());
	float heightPct = (100.0f * (ownTeamSide() * pos.y() + -1.0f * start.y())) / (-1.0f * start.y() + end.y());

	return PositionPct(int(widthPct), int(heightPct));
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

bool Perceptions::isBallkickable() const
{
	return _ball.contains(playerPosition());
}

Vector Perceptions::playerSightDirection() const
{
	return Convertion::toRelativePosition(_player.sightDirection(), ownTeamSide());
}