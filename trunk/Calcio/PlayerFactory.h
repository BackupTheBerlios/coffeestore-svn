#ifndef PLAYER_FACTORY_H
#define PLAYER_FACTORY_H

class Player;

class PlayerFactory
{
public:
	virtual const Player& create(int number) = 0;
};

#endif
