#include "DummyTeamFactory.h"

DummyPlayer::DummyPlayer(const Point& initialPosition, int number)
	:	AbstractPlayer(initialPosition, number)
{

}

void DummyPlayer::run(const Perceptions& perceptions, PlayerAction& playerAction)
{

}

const AbstractPlayer& DummyTeamFactory::createPlayer(int number)
{
	return * new DummyPlayer(Point(50,50), number);
}

