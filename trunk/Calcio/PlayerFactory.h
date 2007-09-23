#ifndef PLAYER_FACTORY_H
#define PLAYER_FACTORY_H

class AbstractPlayer;

class PlayerFactory
{
public:
	virtual const AbstractPlayer& create(int number) = 0;
};

#endif
