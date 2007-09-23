#include "DummyFactory.h"
#include "DummyPlayer.h"

const Player& DummyFactory::create(int number)
{
	return * new DummyPlayer(Point(50,50), number);
}

