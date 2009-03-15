#ifndef NULL_TEAM_H
#define NULL_TEAM_H

#include "AbstractPlayersFactory.h"
#include "AbstractPlayer.h"

class NullPlayer : public AbstractPlayer
{
public:
	NullPlayer();

	void run(const Perceptions& perceptions, PlayerAction& playerAction);
};

class NullTeamFactory : public AbstractPlayersFactory
{
public:
	std::vector<AbstractPlayer*> createPlayers();
	void destroyPlayers(std::vector<AbstractPlayer*>& plys);
};

#endif
