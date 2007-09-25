#include "DummyTeam.h"
#include "Perceptions.h"
#include "Team.h"
#include "Logger.h"
#include "PlayerAction.h"
#include <cmath>

DummyPlayer::DummyPlayer(const Point& initialPosition, int number)
	:	AbstractPlayer(initialPosition, number)
{

}

void DummyPlayer::run(const Perceptions& perceptions, PlayerAction& playerAction)
{
	if (perceptions.ownTeamColor() == Team::Color_RED)
		LOG_STD << "REDS " << number();
	else
		LOG_STD << "BLUES " << number();

	LOG_STD << "Side: " << perceptions.ownTeamSide();
	LOG_STD << "Ball position: " << perceptions.ballPosition();

	for (Perceptions::PerceivedPlayers::const_iterator it = perceptions.visibleOpponent().begin(); it != perceptions.visibleOpponent().end(); ++it)
		LOG_STD << "Opponent " << it->number() << ": " << it->position();

	for (Perceptions::PerceivedPlayers::const_iterator it = perceptions.visibleTeamMate().begin(); it != perceptions.visibleTeamMate().end(); ++it)
		LOG_STD << "Mate " << it->number() << ": " << it->position();

	if (perceptions.ownTeamColor() == Team::Color_BLUE)
		return;

	Point me = perceptions.playerPosition();
	Point ball = perceptions.ballPosition();
	Vector v(me, ball);
	Vector t = v.normalize();
	playerAction.doRun(t);
}

AbstractPlayer& DummyTeamFactory::createPlayer(int number)
{
	if (number == 1)	
		return * new DummyPlayer(Point(23,41), number);
	else
		return * new DummyPlayer(Point(32,21), number);
}
