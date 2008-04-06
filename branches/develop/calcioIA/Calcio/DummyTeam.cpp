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

DummyTeamFactory::DummyTeamFactory( bool flag ) :_flag(flag)
{

}

DummyTeamFactory::~DummyTeamFactory()
{

}

std::vector<AbstractPlayer*> DummyTeamFactory::createPlayers()
{
	std::vector<AbstractPlayer*> pl;
	if (_flag)
		pl.push_back(new DummyPlayer(Point(23,41),1));
	else
		pl.push_back(new DummyPlayer(Point(32,21),1));
	return pl;
}

void DummyTeamFactory::destroyPlayers(std::vector<AbstractPlayer*>& plys)
{
	for(unsigned int ii = 0;ii < plys.size();++ii)
		delete plys[ii];
}

