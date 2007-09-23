#ifndef DUMMY_FACTORY_H
#define DUMMY_FACTORY_H

#include "PlayerFactory.h"

class AbstractPlayer;

class DummyFactory : public PlayerFactory
{
public:
	const AbstractPlayer& create(int number);
};

#endif
