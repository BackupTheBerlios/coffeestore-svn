#include "Perceptions.h"
#include "Team.h"
#include "Game.h"
#include "Player.h"

Perceptions::Perceptions()
	:	_game(NULL)
{

}

const Point& Perceptions::ballPosition() const
{
	return _game->ball().position();
}

const Vector& Perceptions::ballDirection() const
{
	return _game->ball().direction();
}

Team::Players Perceptions::visibleTeamMate(const Player& player) const
{
	const Team& team = _game->team(player.teamColor());
	return Team::Players(team.playersBegin(), team.playersEnd());
}

Team::Players Perceptions::visibleOpponent(const Player& player) const
{
	const Team& team = _game->team((player.teamColor() == Team::Color_BLUE) ? Team::Color_RED : Team::Color_BLUE);
	return Team::Players(team.playersBegin(), team.playersEnd());

}
