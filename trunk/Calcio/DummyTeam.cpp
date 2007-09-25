#include "DummyTeam.h"
#include "Perceptions.h"
#include "Team.h"
#include "Logger.h"
#include "PlayerAction.h"
#include <cmath>
#include <cstdlib>

DummyPlayer::DummyPlayer(const Point& initialPosition, int number)
	:	AbstractPlayer(initialPosition, number)
{

}

void DummyPlayer::run(const Perceptions& perceptions, PlayerAction& playerAction)
{
/*	if (perceptions.ownTeamColor() == Team::Color_RED)
		LOG_STD << "REDS " << number();
	else
		LOG_STD << "BLUES " << number();

	LOG_STD << "Side: " << perceptions.ownTeamSide();
	LOG_STD << "Ball position: " << perceptions.ballPosition();

	for (Perceptions::PerceivedPlayers::const_iterator it = perceptions.visibleOpponent().begin(); it != perceptions.visibleOpponent().end(); ++it)
		LOG_STD << "Opponent " << it->number() << ": " << it->position();

	for (Perceptions::PerceivedPlayers::const_iterator it = perceptions.visibleTeamMate().begin(); it != perceptions.visibleTeamMate().end(); ++it)
		LOG_STD << "Mate " << it->number() << ": " << it->position();
*/
	if (perceptions.ownTeamColor() == Team::Color_BLUE)
		return;

	Point me = perceptions.playerPosition();
	Point ball = perceptions.ballPosition();
	Vector v(me, ball);
	Vector t = v.normalize();

	static float dir = 1;

	if (me.x() > 100 && me.y() > 100)
	{
		dir = -1;
		playerAction.doKick(Vector(-5,-5));
		playerAction.doRun(Vector(-3, -3));
		return;
	}

	if (me.x() < 0 && me.y() < 0)
	{
		dir = 1;
		playerAction.doKick(Vector(5,5));
		playerAction.doRun(Vector(3, 3));
		return;
	}

	if (perceptions.isBallkickable())
	{
		LOG_STD << "kick " << t;
		playerAction.doKick(t + (Vector((float)rand(), (float)rand())*dir).normalize());
		if (dir==-1)
			playerAction.doRun(t);
	}
	else
	{
		LOG_STD << "move " << t;
		playerAction.doRun(t);
	}
}

AbstractPlayer& DummyTeamFactory::createPlayer(int number)
{
	if (number == 1)	
		return * new DummyPlayer(Point(23,41), number);
	else
		return * new DummyPlayer(Point(32,21), number);
}
