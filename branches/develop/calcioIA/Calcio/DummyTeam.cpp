#include "DummyTeam.h"
#include "Perceptions.h"
#include "Team.h"
#include "PlayerAction.h"
#include <cmath>
#include <cstdlib>
#include "MathFun.h"

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
		playerAction.doKick(t + (Vector((float)rand(), (float)rand())*dir).normalize());
		if (dir==-1)
			playerAction.doRun(t);
	}
	else
	{
		playerAction.doRun(t);
	}
}

DummyTeamFactory::~DummyTeamFactory()
{

}

std::vector<AbstractPlayer*> DummyTeamFactory::createPlayers()
{
	std::vector<AbstractPlayer*> pl;
	Point init(0.0f,0.0f);
	for (unsigned int ii = 0; ii < 1;++ii)
	{	
		pl.push_back(new DummyPlayer(Point(init.x(),init.y()),ii + 1));
		init = init + Point(0.0,5.0);
	}
	return pl;
}

void DummyTeamFactory::destroyPlayers(std::vector<AbstractPlayer*>& plys)
{
	for(unsigned int ii = 0;ii < plys.size();++ii)
		delete plys[ii];
}


DummyVoyeurPlayer::DummyVoyeurPlayer( const Point& initialPosition, int number )
:	AbstractPlayer(initialPosition, number)
{
}

void DummyVoyeurPlayer::run( const Perceptions& perceptions, PlayerAction& playerAction )
{
	Point me = perceptions.playerPosition();
	Vector see = perceptions.playerSightDirection();
	Point ball = perceptions.ballPosition();
	Vector v(me, ball);
	float angle = std::acos(v.normalize() * see);	
	playerAction.doTurnHead(mathfun::rad2Deg(angle));
}

DummyVoyeurTeamFactory::~DummyVoyeurTeamFactory()
{

}

std::vector<AbstractPlayer*> DummyVoyeurTeamFactory::createPlayers()
{
	std::vector<AbstractPlayer*> pl;
	Point init(0.0f,0.0f);
	for (unsigned int ii = 0; ii < 1;++ii)
	{	
		pl.push_back(new DummyVoyeurPlayer(Point(init.x(),init.y()),ii + 1));
		init = init + Point(0.0,5.0);
	}
	return pl;
}

void DummyVoyeurTeamFactory::destroyPlayers(std::vector<AbstractPlayer*>& plys)
{
	for(unsigned int ii = 0;ii < plys.size();++ii)
		delete plys[ii];
}