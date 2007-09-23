#ifndef TEAM_FACTORY_H
#define TEAM_FACTORY_H

#include "AbstractPlayer.h"

class DummyPlayer : public AbstractPlayer
{
public:
	DummyPlayer(const Point& initialPosition, int number);

	void run(const Perceptions& perceptions, PlayerAction& playerAction);
};

class TeamFactory
{
public:
	virtual const AbstractPlayer& createPlayer(int number) = 0;
};

#endif
