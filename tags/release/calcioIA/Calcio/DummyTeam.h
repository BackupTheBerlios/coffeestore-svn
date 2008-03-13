#ifndef DUMMY_TEAM_H
#define DUMMY_TEAM_H

#include "AbstractPlayersFactory.h"
#include "AbstractPlayer.h"

class DummyPlayer : public AbstractPlayer
{
public:
	DummyPlayer(const Point& initialPosition, int number);

	void run(const Perceptions& perceptions, PlayerAction& playerAction);


};

class DummyTeamFactory : public AbstractPlayersFactory
{
public:
	DummyTeamFactory(bool flag)
		:_flag(flag)
	{
	}

	std::vector<AbstractPlayer*> createPlayers();
	void destroyPlayers(std::vector<AbstractPlayer*>& plys);

	~DummyTeamFactory(){};

private:
	bool _flag;
};

#endif
