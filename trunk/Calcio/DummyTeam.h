#ifndef DUMMY_TEAM_FACTORY_H
#define DUMMY_TEAM_FACTORY_H

#include "TeamFactory.h"

class DummyPlayer : public AbstractPlayer
{
public:
	DummyPlayer(const Point& initialPosition, int number);

	void run(const Perceptions& perceptions, PlayerAction& playerAction);
};

class DummyTeamFactory : public TeamFactory
{
public:
	const AbstractPlayer& createPlayer(int number);
};

#endif
