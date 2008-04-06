#ifndef ABSTRACT_PLAYERS_FACTORY_H
#define ABSTRACT_PLAYERS_FACTORY_H

#include <vector>

class AbstractPlayer;

class AbstractPlayersFactory
{
public:
	virtual std::vector<AbstractPlayer*> createPlayers() = 0;
	virtual void destroyPlayers(std::vector<AbstractPlayer*>& plys) = 0;
	virtual ~AbstractPlayersFactory() {}
};

#endif
