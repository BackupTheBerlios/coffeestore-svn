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
	{	
		Point init(0.0f,0.0f);
		for (unsigned int ii = 0; ii < 11;++ii)
		{
			pl.push_back(new DummyPlayer(Point(init.x(),init.y()),ii + 1));
			init = init  + Point(0.0,5.0);
		}
	}
	else
	{
			Point init(0.0f,0.0f);
			for (unsigned int ii = 0; ii < 11;++ii)
			{	
				pl.push_back(new DummyPlayer(Point(init.x(),init.y()),ii + 1));
				init = init + Point(0.0,5.0);
			}
	}
	return pl;
}

void DummyTeamFactory::destroyPlayers(std::vector<AbstractPlayer*>& plys)
{
	for(unsigned int ii = 0;ii < plys.size();++ii)
		delete plys[ii];
}

