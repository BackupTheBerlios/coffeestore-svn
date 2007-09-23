#ifndef DUMMY_TEAM_H
#define DUMMY_TEAM_H

#include "TeamFactory.h"
#include "AbstractPlayer.h"

class DummyPlayer : public AbstractPlayer
{
public:
	DummyPlayer(const Point& initialPosition, int number);

	void run(const Perceptions& perceptions, PlayerAction& playerAction);
};

class DummyTeamFactory : public TeamFactory
{
public:
	AbstractPlayer& createPlayer(int number);
};

#endif
