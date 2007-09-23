#include "DummyTeam.h"
#include "Perceptions.h"
#include "Team.h"

#include <iostream>
using namespace std;

DummyPlayer::DummyPlayer(const Point& initialPosition, int number)
	:	AbstractPlayer(initialPosition, number)
{

}

void DummyPlayer::run(const Perceptions& perceptions, PlayerAction& playerAction)
{
	if (perceptions.ownTeamColor() == Team::Color_RED)
		cout << "REDS " << number() << endl;
	else
		cout << "BLUES " << number() << endl;

	cout << "Side: " << perceptions.ownTeamSide() << endl;
	cout << "Ball position: " << perceptions.ballPosition() << endl;

	for (Perceptions::PerceivedPlayers::const_iterator it = perceptions.visibleOpponent().begin(); it != perceptions.visibleOpponent().end(); ++it)
		cout << "Opponent " << it->number() << ": " << it->position() << endl;

	for (Perceptions::PerceivedPlayers::const_iterator it = perceptions.visibleTeamMate().begin(); it != perceptions.visibleTeamMate().end(); ++it)
		cout << "Mate " << it->number() << ": " << it->position() << endl;
}

AbstractPlayer& DummyTeamFactory::createPlayer(int number)
{
	if (number == 1)	
		return * new DummyPlayer(Point(23,41), number);
	else
		return * new DummyPlayer(Point(32,21), number);
}
