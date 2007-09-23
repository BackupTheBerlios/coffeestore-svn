#include "DummyFactory.h"
#include "DummyPlayer.h"

const AbstractPlayer& DummyFactory::create(int number)
{
	return * new DummyPlayer(Point(50,50), number);
}

