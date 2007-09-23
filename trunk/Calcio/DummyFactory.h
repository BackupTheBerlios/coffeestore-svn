#ifndef DUMMY_FACTORY_H
#define DUMMY_FACTORY_H

class Player;

class DummyFactory
{
public:
	const Player& create(int number);
};

#endif
